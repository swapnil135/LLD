#include <bits/stdc++.h>

using namespace std;

string rootDir = "root";
class File {
public:
    bool isDir;
    string content;
    string path;
    map<string, File*> children = {};
    File(){
        this->isDir = true;
    }
    File(bool isDir, string path){
        this->isDir = isDir;
        this->path = path; 
    }

    File(bool isDir, string path, string content){
        this->isDir = isDir;
        this->path = path;
        this->content = content;
    }
};
    
class FileSystem {
    public:
        File root;
        FileSystem(){
            this -> root = File(true, rootDir);
        }

        vector<string> ls(string path){
            vector<string> res;
            int depth = 0;
            File* currDir = &root;
            while(getNextDir(path, depth, '/') != ""){
                currDir = currDir -> children[getNextDir(path, depth, '/')];
                depth++;
            }

            if (currDir->isDir){
                for(auto file:currDir->children){
                    res.push_back(file.first);
                }
            } else {
                res.push_back(currDir -> path);
            }
            return res;
        }

        void mkDir(string directory){
            string totalPath = rootDir;
            int depth = 0;
            File* currDir = &root;
            
            while(getNextDir(directory, depth, '/') != ""){
                string nextDir = getNextDir(directory, depth, '/');
                if (currDir -> children[nextDir] == NULL){
                    currDir->children[nextDir] = new File(true, totalPath);
                }
                currDir = currDir -> children[nextDir]; 
                depth++;
                totalPath = totalPath + "/" + nextDir;
            }

            cout<<"dir created:"<<totalPath<<endl;
        }

        void addContentToFile(string path, string content){
            string totalPath = rootDir;
            int depth = 0;
            File* currDir = &root;
            while(getNextDir(path, depth, '/') != ""){
                string nextDir = getNextDir(path, depth, '/');
                if (currDir -> children[nextDir] == NULL){
                    currDir->children[nextDir] = new File(true, totalPath);
                }
                currDir = currDir -> children[nextDir]; 
                depth++;
                totalPath = totalPath + "/" + nextDir;
            }

            currDir -> isDir = false;
            currDir -> content = content;
        }

        string readContentFromFile(string path){
            int depth = 0;
            File* currDir = &root;
            try {
                while(getNextDir(path, depth, '/') != ""){
                string nextDir = getNextDir(path, depth, '/');
                if (currDir -> children[nextDir] == NULL){
                    throw runtime_error("invalid directory");
                }
                currDir = currDir -> children[nextDir]; 
                depth++;
            }
            }
            catch (const exception& e){
                cout<<"Error:"<<e.what()<<endl;
                return "";
            }
            

            return currDir->content;
        }
    
    private:
        // returns empty string if directory does not exist at given depth
        string getNextDir(string path, int depth, char delim){
            int delimCount = 0;
            string currDir;
            int i=0;
            while(i<path.size()){
                if(path[i] == delim){
                    if(delimCount == depth){
                        return currDir;
                    }
                    else{
                        currDir = "";
                        delimCount++;
                        i++;
                    }
                }
                currDir.push_back(path[i]);
                i++;
            }
            if(delimCount == depth){
                        return currDir;
                    }
                    return "";
        }
};

int main() {
    FileSystem fs = FileSystem();

    while(true) {
        string input;
        cout<<"available commands: ls, mkdir, addcontent, readcontent"<<endl;

        string path, content;

        cin>>input;
        if( input == "ls"){
            cout<<"enter path"<<endl;
            cin>>path;
            for(auto path:fs.ls(path)){
                cout<<path<<endl;
            }
            continue;
        }
        if( input == "mkdir"){
            cout<<"enter path"<<endl;
            cin>>path;
            fs.mkDir(path);
            continue;
        }
        if( input == "addcontent"){
            cout<<"enter path"<<endl;
            cin>>path;
            cout<<"enter content"<<endl;
            cin>>content;
            fs.addContentToFile(path, content);
            continue;
        }
        if( input == "readcontent"){
            cout<<"enter path"<<endl;
            cin>>path;
            cout<<fs.readContentFromFile(path)<<endl;
            continue;
        }

        cout<<"invalid input"<<endl;
    }
}