#include "CollisionRecord.h"
#include <algorithm>
#include <omp.h>
using namespace std;

void CollisionRecords::addRecord(int id, const string& date, float latitude, float longitude) {
    ids.push_back(id);
    dates.push_back(date);
    latitudes.push_back(latitude);
    longitudes.push_back(longitude);
}

void CollisionRecords::clear() {
    ids.clear();
    dates.clear();
    latitudes.clear();
    longitudes.clear();
}

void CollisionRecords::reserve(size_t capacity) {
    ids.reserve(capacity);
    dates.reserve(capacity);
    latitudes.reserve(capacity);
    longitudes.reserve(capacity);
}

vector<size_t> CollisionRecords::getIndicesInLatitudeRange(float minLat, float maxLat) const {
    vector<size_t> result;
    result.reserve(latitudes.size() / 4); 

    #pragma omp parallel
    {
        vector<size_t> local_result;
        local_result.reserve(latitudes.size() / 4);

        #pragma omp for nowait
        for (size_t i = 0; i < latitudes.size(); ++i) {
            if (latitudes[i] >= minLat && latitudes[i] <= maxLat) {
                local_result.push_back(i);
            }
        }

        #pragma omp critical
        {
            result.insert(result.end(), local_result.begin(), local_result.end());
        }
    }

    return result;
}