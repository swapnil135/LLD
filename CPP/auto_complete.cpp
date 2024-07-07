#include <bits/stdc++.h>

using namespace std;

class LetterNode {
    private:
    int weight;
    bool isWord;
    map<char, LetterNode*> children;

    public:
    LetterNode(bool isWord){
        this->isWord = isWord;
        this->weight = 1;
    }

    bool isWordEnding(){
        return this->isWord;
    }

    void markWord(){
        this->isWord = true;
    }

    int getWeight(){
        return this->weight;
    }

    void addChild(char letter, bool isWord){
        this->children[letter] = new LetterNode(isWord);
    }

    LetterNode* getChild(char c){
        return this->children[c];
    }
};

class Dictionary {
    private:
    LetterNode* root;
    // returns all the words branching from node first
    vector<string> getAllWords(LetterNode* first){
        vector<string> words;
        traverseNode(first, words, "");
        return words;
    }

    void traverseNode(LetterNode* currNode, vector<string>& words, string currString){
        if(currNode -> isWordEnding()){
            words.push_back(currString);
        }

        for(char c = 'a'; c<= 'z'; c++){
            if(currNode->getChild(c)!= NULL){
                currString.push_back(c);
                traverseNode(currNode->getChild(c), words, currString);
                currString.pop_back();
            }
        }
    }

    public:
    Dictionary(){
        root = new LetterNode(false);
    }

    void AddWord(string word){
        auto curr = root;
        for(int i=0; i<word.size(); i++){
            if(curr->getChild(word[i]) == NULL){
                curr->addChild(word[i], false);
            }

            if(i == word.size()-1){
                curr->getChild(word[i])->markWord();
            }

            curr = curr->getChild(word[i]);
        }
    }

    vector<string> getSuggestions(string input){
        string curr = "";
        auto currNode = this->root;
        for(int i=0; i<input.size(); i++){
            currNode = currNode->getChild(input[i]);
            if(currNode == NULL) return {};
        }

        return getAllWords(currNode);
    }
};

int main(){
    Dictionary dic = Dictionary();
    // commands - add, get, exit

    while(1){
        cout<<"available commands - add, get, exit"<<endl;
        string input;
        cin>>input;
        if(input == "add"){
            cout<<"type word to add"<<endl;
            string word;
            cin>>word;
            dic.AddWord(word);
            cout<<"word added";
        } else if(input == "get"){
            string word;
            cout<<"type word for suggestion"<<endl;
            cin>>word;
            auto res = dic.getSuggestions(word);
            cout<<"suggestions: "<<endl;
            for(string w:res){
                cout<<word<<w<<endl;
            }
            cout<<"------"<<endl;
        } else if(input =="exit"){
            break;
        }
    }
}