#ifndef COLLISION_RECORD_H
#define COLLISION_RECORD_H

#include <string>
using namespace std;

class CollisionRecord {
public:
    int id;               
    string date;     
    float latitude;       
    float longitude;      
    
    CollisionRecord(int id, const string& date, float latitude, float longitude)
        : id(id), date(date), latitude(latitude), longitude(longitude) {}
};

#endif 