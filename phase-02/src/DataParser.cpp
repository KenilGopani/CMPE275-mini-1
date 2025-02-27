#include "DataParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <omp.h>

using namespace std;

vector<CollisionRecord> DataParser::parseCSV(const string& filePath) {
    vector<CollisionRecord> records;
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filePath << endl;
        return records;
    }

    string line;
    getline(file, line);

    size_t lineCount = 0;
    while (getline(file, line)) {
        ++lineCount;
    }
    file.clear();
    file.seekg(0);
    getline(file, line); 
    records.reserve(lineCount);

    vector<string> lines(lineCount);
    size_t idx = 0;
    while (getline(file, line)) {
        lines[idx++] = line;
    }

    #pragma omp parallel
    {
        vector<CollisionRecord> localRecords;
        localRecords.reserve(lineCount / omp_get_num_threads());

        #pragma omp for nowait
        for (size_t i = 0; i < lineCount; ++i) {
            stringstream ss(lines[i]);
            int id;
            string date;
            float latitude, longitude;
            char delimiter;

            ss >> id >> delimiter >> date >> delimiter >> latitude >> delimiter >> longitude;
            localRecords.emplace_back(id, date, latitude, longitude);
        }

        #pragma omp critical
        {
            records.insert(records.end(), localRecords.begin(), localRecords.end());
        }
    }

    file.close();
    return records;
}

vector<CollisionRecord> DataParser::searchByLatitudeRange(
    const vector<CollisionRecord>& records,
    float minLat,
    float maxLat
) {
    vector<CollisionRecord> result;
    result.reserve(records.size());

    #pragma omp parallel
    {
        vector<CollisionRecord> localMatches;
        localMatches.reserve(records.size() / omp_get_num_threads());

        #pragma omp for nowait
        for (size_t i = 0; i < records.size(); ++i) {
            if (records[i].latitude >= minLat && records[i].latitude <= maxLat) {
                localMatches.push_back(records[i]);
            }
        }

        #pragma omp critical
        {
            result.insert(result.end(), localMatches.begin(), localMatches.end());
        }
    }

    return result;
}
