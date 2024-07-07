#include <bits/stdc++.h>

using namespace std;

// implementation of concurrency concepts (mutex and lock gaurd)
class BoundedQueue{
    private:
    queue<string> internalQueue;
    int size;
    mutex mutex_;
    condition_variable size_full;
    condition_variable empty_queue;

    public:
    BoundedQueue(int size){
        this->size = size;
    }

    // this function will pop an element out from a queue in a thread safe manner
    // if queue is empty it will wait till an element is present in it
    string pop(){
        unique_lock<mutex> lock(mutex_);
        // release the lock till there is a thread that pushes an element
        // and free up system resources
        empty_queue.wait(lock, [this]{return !this->internalQueue.empty();});
        string message = internalQueue.front();
        internalQueue.pop();
        size_full.notify_one();
        return message;
    }

    // this funciton will wait till there is space in the queue and then insert the element.
    void push(string item){
        unique_lock<mutex> lock(mutex_);
        size_full.wait(lock, [this]{return this->internalQueue.size() < this->size;});
        this->internalQueue.push(item);
        empty_queue.notify_one();
    }
};