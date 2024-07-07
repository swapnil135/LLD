#include <bits/stdc++.h>

// list of coordinates are given, implement two functions:
// GetLocalMaximas()
// GetGlobalMaxima()

using namespace std;

class Coordinate {
    private:
    int x;
    int y;

    public:
    int GetX(){
        return this->x;
    }

    int GetY(){
        return this->y;
    }
};

class Maxima {
    private:
    vector<Coordinate> points;

    public:
    Maxima(vector<Coordinate> points){
        this->points = points;
    }

    vector<Coordinate> GetLocalMaximas(){

    }

    Coordinate GetGlobalMaxima(){
        
    }
}

int main () {

}