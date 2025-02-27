#include "DataParser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <omp.h>

using namespace std;

CollisionRecords DataParser::parseCSV(const string& filePath) {
    CollisionRecords records;
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filePath << endl;
        return records;
    }

    size_t lineCount = 0;
    string line;
    getline(file, line); 
    while (getline(file, line)) {
        ++lineCount;
    }

    records.reserve(lineCount);

    file.clear();
    file.seekg(0);
    getline(file, line); 

    #pragma omp parallel
    {
        string local_line;
        vector<string> local_lines;
        local_lines.reserve(lineCount / omp_get_num_threads());

        #pragma omp for nowait
        for (size_t i = 0; i < lineCount; ++i) {
            #pragma omp critical
            {
                if (getline(file, local_line)) {
                    local_lines.push_back(local_line);
                }
            }
        }

        for (const auto& line : local_lines) {
            stringstream ss(line);
            int id;
            string date;
            float latitude, longitude;

            char delimiter;
            ss >> id >> delimiter >> date >> delimiter >> latitude >> delimiter >> longitude;

            #pragma omp critical
            {
                records.addRecord(id, date, latitude, longitude);
            }
        }
    }

    file.close();
    return records;
}

vector<size_t> DataParser::searchByLatitudeRange(
    const CollisionRecords& records,
    float minLat,
    float maxLat
) {
    return records.getIndicesInLatitudeRange(minLat, maxLat);
}