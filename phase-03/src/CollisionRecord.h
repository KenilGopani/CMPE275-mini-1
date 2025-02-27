#ifndef COLLISION_RECORD_H
#define COLLISION_RECORD_H

#include <string>
#include <vector>

using namespace std;

class CollisionRecords {
public:
    void addRecord(int id, const string& date, float latitude, float longitude);

    int getId(size_t index) const { return ids[index]; }
    const string& getDate(size_t index) const { return dates[index]; }
    float getLatitude(size_t index) const { return latitudes[index]; }
    float getLongitude(size_t index) const { return longitudes[index]; }

    size_t size() const { return ids.size(); }

    vector<size_t> getIndicesInLatitudeRange(float minLat, float maxLat) const;

    void clear();

    void reserve(size_t capacity);

private:
    vector<int> ids;
    vector<string> dates;
    vector<float> latitudes;
    vector<float> longitudes;
};

#endif 