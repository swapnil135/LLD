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

class Car {
    private:
    string regNumber;
    string color;
    public:
    string getColor(){

    }
    string getRegNumber(){

    }
};

class Slot {
    public:
    bool isOccupied;
    string carRegNumber;
    Slot(){

    }
    void OccupySlot(Car car){
        this->isOccupied = true;
        this->carRegNumber = car.getRegNumber();
    }
    void FreeSlot(){
        this->isOccupied = false;
        this->carRegNumber = "";
    }
};

class Ticket {
    private:
    bool isValid;
    int slot;
    string regNumber;
    string ticketNumber;

    public:
    Ticket(int slot, string regNumber){
        this->isValid = true;
        this -> slot = slot;
        this -> regNumber = regNumber;
        this -> ticketNumber = gen_random(5);
    }

    string getRegNumber(){
        return this->regNumber;
    }

    int getSlot(){
        return this->slot;
    }

    string markInvalid(){
        this->isValid = false;
    }

    string getId(){
        return this->ticketNumber;
    }
};

class ParkingLot {
    private:
    map<string, Ticket*> ticketIdMap;
    vector<Slot> slots;
    int size;
    set<int> emptySlots;
    priority_queue<int, vector<int>, greater<int>> nearestEmpty;

    public:
    ParkingLot(int size){
        this->size = size;
        for(int i=0; i<size; i++) {
            this->nearestEmpty.push(i);
            emptySlots.insert(i);
        }
        slots = vector<Slot>(size, Slot());
    }

    string ParkCar(Car car){
        int slot = bookNextSlot();
        auto ticketPtr = new Ticket(slot, car.getRegNumber());
        ticketIdMap[ticketPtr->getId()] = ticketPtr;
        slots[slot].OccupySlot(car);
    }

    string ExitCar(string ticketId){
        Ticket* ticket = ticketIdMap[ticketId];
        ticket->markInvalid();
        delete ticket;
        slots[ticket->getSlot()].FreeSlot();
        emptySlot(ticket->getSlot());
    }

    private:
    int bookNextSlot(){
        return nearestEmpty.top();
        nearestEmpty.pop();
    }

    void emptySlot(int slot){
        if(!emptySlots.count(slot)){
            nearestEmpty.push(slot);
            emptySlots.insert(slot);
        }
    }
}

int main(){

}