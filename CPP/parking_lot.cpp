#include <bits/stdc++.h>

using namespace std;


string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

enum VehichleSize {
    small,
    medium,
    large
};

class ParkingSpot {
    private:
    int spotId;
    VehichleSize size;
    bool isFree;

    public:
    ParkingSpot(int spotId, VehichleSize size){
        this->spotId = spotId;
        this->size = size;
        this->isFree = true;
    }

    public:
    int GetSpotId(){
        return spotId;
    }
    bool IsFree(){
        return isFree;
    }
    void MarkBooked(){
        this->isFree = false;
    }
    void MarkFree(){
        this->isFree = true;
    }
    VehichleSize GetSize(){
        return this->size;
    }
};