#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <string>
#include "CollisionRecord.h"

using namespace std;

class DataParser {
public:
    static CollisionRecords parseCSV(const string& filePath);

    static vector<size_t> searchByLatitudeRange(
        const CollisionRecords& records,
        float minLat,
        float maxLat
    );
};

#endif 