#include "DataParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

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

    while (getline(file, line)) {
        stringstream ss(line);
        int id;
        string date;
        float latitude, longitude;

        char delimiter;
        ss >> id >> delimiter >> date >> delimiter >> latitude >> delimiter >> longitude;

        records.emplace_back(id, date, latitude, longitude);
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

    for (const auto& record : records) {
        if (record.latitude >= minLat && record.latitude <= maxLat) {
            result.push_back(record);
        }
    }

    return result;
}
