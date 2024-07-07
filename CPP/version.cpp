#include <bits/stdc++.h>

using namespace std;

class VersionManagement
{
    public:
    virtual void addVersion(long versionNumber, bool isCompatibleWithPrev) = 0;
    virtual bool isCompatible(long version1, long version2) = 0;
};

class unionFind{
    private:
    // stores the parent of ith member.
    vector<int> parents;
    int size = 0;
    int getParent(int u){
        if(parents[u] == u){
            return u;
        }

        return getParent(parents[u]);
    }

    public:
    unionFind(){}
    // adds a member to the unionFind and returns the index of the member in parents.
    int addMember(){
        size++;
        parents.push_back(size-1);
        return size-1;
    }

    void unite(int u, int v){
        parents[u] = getParent(parents[v]);
    }

    bool belongsToSameSet(int u, int v){
        return getParent(u) == getParent(v);
    }
};


class VersionManagementImpl : public VersionManagement {
    private:
    map<int,int> versionToUFMapping;
    unionFind uf;
    long latestVersion = -1;

    public:
    void addVersion(long versionNumber, bool isCompatibleWithPrev){
        int versionKey = uf.addMember();
        if(latestVersion != -1 && isCompatibleWithPrev){
            uf.unite(versionKey, versionToUFMapping[latestVersion]);
        }
    }
    bool isCompatible(long version1, long version2){
        return uf.belongsToSameSet(versionToUFMapping[version1], versionToUFMapping[version2]);
    }
};

class Interface {
    public:
    virtual void method(string arg2) = 0;
};

class concrete: public Interface {
    
};