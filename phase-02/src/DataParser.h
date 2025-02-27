#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <vector>
#include <string>
#include "CollisionRecord.h"

using namespace std;

class DataParser {
public:
    static vector<CollisionRecord> parseCSV(const string& filePath);

    static vector<CollisionRecord> searchByLatitudeRange(
        const vector<CollisionRecord>& records,
        float minLat,
        float maxLat
    );
};

#endif 