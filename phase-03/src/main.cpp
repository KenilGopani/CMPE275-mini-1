#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstdio>
#include <unistd.h>
#include <omp.h>
#include <numeric>
#include "DataParser.h"
#include "CollisionRecord.h"
#include <mach/mach.h>

using namespace std;

size_t getCurrentMemoryUsage() {
    mach_task_basic_info_data_t info;
    mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
    if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &count) == KERN_SUCCESS) {
        return info.resident_size;  
    }
    return 0;  
}

int main() {
    omp_set_num_threads(4);
    const int NUM_ITERATIONS = 10;
    
    string filePath = "./../../Motor_Vehicle_Collisions_-_Crashes_20250215.csv";
    float minLat = 40.0f, maxLat = 41.0f;
    
    cout << "Phase 3 - Optimized Data Structure Implementation (" << NUM_ITERATIONS << " iterations)" << endl;
    cout << "==========================================" << endl;
    
    vector<double> parseWallTimes(NUM_ITERATIONS);
    vector<double> parseCpuTimes(NUM_ITERATIONS);
    vector<size_t> parseMemoryUsages(NUM_ITERATIONS);
    vector<double> searchWallTimes(NUM_ITERATIONS);
    vector<double> searchCpuTimes(NUM_ITERATIONS);
    vector<size_t> searchMemoryUsages(NUM_ITERATIONS);
    size_t totalRecords = 0;
    size_t totalFilteredRecords = 0;

    for (int iter = 0; iter < NUM_ITERATIONS; ++iter) {
        cout << "\nIteration " << iter + 1 << ":" << endl;
        cout << "-------------" << endl;

        auto parseStart = chrono::high_resolution_clock::now();
        clock_t parseCpuStart = clock();
        size_t initialMemory = getCurrentMemoryUsage();

        CollisionRecords records = DataParser::parseCSV(filePath);

        auto parseEnd = chrono::high_resolution_clock::now();
        clock_t parseCpuEnd = clock();
        size_t parseMemory = getCurrentMemoryUsage();

        parseWallTimes[iter] = chrono::duration<double>(parseEnd - parseStart).count();
        parseCpuTimes[iter] = static_cast<double>(parseCpuEnd - parseCpuStart) / CLOCKS_PER_SEC;
        parseMemoryUsages[iter] = parseMemory - initialMemory;

        auto searchStart = chrono::high_resolution_clock::now();
        clock_t searchCpuStart = clock();
        size_t searchInitialMemory = getCurrentMemoryUsage();

        vector<size_t> matchingIndices = DataParser::searchByLatitudeRange(records, minLat, maxLat);

        auto searchEnd = chrono::high_resolution_clock::now();
        clock_t searchCpuEnd = clock();
        size_t searchPeakMemory = getCurrentMemoryUsage();

        searchWallTimes[iter] = chrono::duration<double>(searchEnd - searchStart).count();
        searchCpuTimes[iter] = static_cast<double>(searchCpuEnd - searchCpuStart) / CLOCKS_PER_SEC;
        searchMemoryUsages[iter] = searchPeakMemory - searchInitialMemory;

        totalRecords = records.size();
        totalFilteredRecords = matchingIndices.size();

        cout << "Data Loading:" << endl;
        cout << "  Records loaded: " << records.size() << endl;
        cout << "  Wall time: " << fixed << setprecision(3) << parseWallTimes[iter] << " seconds" << endl;
        cout << "  CPU time: " << fixed << setprecision(3) << parseCpuTimes[iter] << " seconds" << endl;
        cout << "  Memory usage: " << parseMemoryUsages[iter] / 1024 << " KB" << endl;

        cout << "\nLatitude Range Search:" << endl;
        cout << "  Range: [" << minLat << ", " << maxLat << "]" << endl;
        cout << "  Records found: " << matchingIndices.size() << endl;
        cout << "  Wall time: " << fixed << setprecision(6) << searchWallTimes[iter] << " seconds" << endl;
        cout << "  CPU time: " << fixed << setprecision(6) << searchCpuTimes[iter] << " seconds" << endl;
        cout << "  Memory usage: " << searchMemoryUsages[iter] / 1024 << " KB" << endl;

        size_t totalMemoryPeak = max(parseMemory, searchPeakMemory) - initialMemory;
        cout << "\nTotal Memory Peak: " << totalMemoryPeak / 1024 << " KB" << endl;
    }
    
    auto calcAvg = [](const vector<double>& v) {
        return accumulate(v.begin(), v.end(), 0.0) / v.size();
    };
    auto calcAvgSize = [](const vector<size_t>& v) {
        return accumulate(v.begin(), v.end(), 0ULL) / v.size();
    };

    cout << "\n=================================" << endl;
    cout << "Average Performance Metrics:" << endl;
    cout << "=================================" << endl;
    cout << "Data Loading:" << endl;
    cout << "  Records loaded: " << totalRecords << endl;
    cout << "  Average Wall time: " << fixed << setprecision(3) << calcAvg(parseWallTimes) << " seconds" << endl;
    cout << "  Average CPU time: " << fixed << setprecision(3) << calcAvg(parseCpuTimes) << " seconds" << endl;
    cout << "  Average Memory usage: " << calcAvgSize(parseMemoryUsages) / 1024 << " KB" << endl;

    cout << "\nLatitude Range Search:" << endl;
    cout << "  Range: [" << minLat << ", " << maxLat << "]" << endl;
    cout << "  Records found: " << totalFilteredRecords << endl;
    cout << "  Average Wall time: " << fixed << setprecision(6) << calcAvg(searchWallTimes) << " seconds" << endl;
    cout << "  Average CPU time: " << fixed << setprecision(6) << calcAvg(searchCpuTimes) << " seconds" << endl;
    cout << "  Average Memory usage: " << calcAvgSize(searchMemoryUsages) / 1024 << " KB" << endl;

    return 0;
}