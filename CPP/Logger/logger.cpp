#include <bits/stdc++.h>

using namespace std;

// this problem implements singelton design pattern
class KeyValueStorage {
    public:
    virtual void AddKey(string key, string value) = 0;
    virtual void UpdateKey(string key, string value) = 0;
    virtual string GetKey(string key) = 0;
    virtual void DeleteKey(string key) = 0;
};

class ConcurrentMapStorage: public KeyValueStorage {
    private:
    map<string, string> mp;
    mutex mx;
    static ConcurrentMapStorage* storagePtr;
    ConcurrentMapStorage(){}

    public:
    // delete copy constructor
    ConcurrentMapStorage(const ConcurrentMapStorage& obj) = delete;

    static ConcurrentMapStorage* GetInstance(){
        if(storagePtr == NULL){
            storagePtr = new ConcurrentMapStorage();
        }

        return storagePtr;
    }
    
    void AddKey(string key, string value){
        lock_guard<mutex> lock(mx);
        if(mp[key] != ""){
            cout<<"key already exists, delete the key or use update"<<endl;
            throw invalid_argument("key laready exists");
        }

        mp[key] = value;
    }

    void UpdateKey(string key, string value){
        lock_guard<mutex> lock(mx);
        if(mp[key] == ""){
            throw invalid_argument("key is not set, can not update");
        }

        mp[key] = value;
    }

    string GetKey(string key){
        lock_guard<mutex> lock(mx);
        if(mp[key] == ""){
            throw invalid_argument("key does not exist");
        }

        return mp[key];
    }

    void DeleteKey(string key){
        lock_guard<mutex> lock(mx);
        if(mp[key] == ""){
            throw invalid_argument("key does not exist");
        }

        mp.erase(key);
    }
};

class ConfigStorage {
    public:
    virtual void AddConfig(string key, string value) = 0;
    virtual string GetConfig(string key) = 0;
    virtual void UpdateConfig(string key, string value) = 0;
    virtual void DeleteConfig(string key) = 0;
};

class ConfigStorageImpl:ConfigStorage {
    private:
    KeyValueStorage* dataStore;
    static ConfigStorageImpl* instancePtr;
    ConfigStorageImpl(KeyValueStorage* storage){
        this->dataStore = storage;
    }

    public:
    // delete copy constructor
    ConfigStorageImpl(const ConfigStorageImpl& obj) = delete;

    static ConfigStorageImpl* GetInstance(){
        if (instancePtr == NULL){
            KeyValueStorage* storage = ConcurrentMapStorage::GetInstance();
            instancePtr = new ConfigStorageImpl(storage);
        }

        return instancePtr;
    }

    void AddConfig(string key, string value){
        try
        {
            dataStore->AddKey(key, value);
        }
        catch(const exception& e)
        {
            string err = string(e.what());
            throw runtime_error("error in add key:" + err);
        }
        
    }

    string GetConfig(string key){
        string val;
        try
        {
            dataStore->GetKey(key);
        }
        catch(const std::exception& e)
        {
            string err = string(e.what());
            throw runtime_error("error in Get key:" + err);
        }
        
    }
    void UpdateConfig(string key, string value){
        try
        {
            dataStore->UpdateKey(key, value);
        }
        catch(const std::exception& e)
        {
            string err = string(e.what());
            throw runtime_error("error in update key:" + err);
        }
    }

    void DeleteConfig(string key){
        try
        {
            dataStore->DeleteKey(key);
        }
        catch(const std::exception& e)
        {
            string err = string(e.what());
            throw runtime_error("error in delete key:" + err);
        }
    }
    
};

