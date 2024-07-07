#include <bits/stdc++.h>

using namespace std;

class ContactFinder {
};


int main(){
    ContactFinder* cf = new ContactFinder();

    while(true){
        cout<<"commands: add, search"<<endl;
        string input;
        cin>>input;

        if(input == "add"){
            string name, number;
            cout<<"enter name"<<endl;
            cin>>name;
            cout<<"enter number"<<endl;
            cin>>number;

            cf->AddContact(name, number);
            cout<<"number added"<<endl;
        } else if (input == "search"){
            string name;
            cout<<"enter name"<<endl;
            cin>>name;

            vector<string> res = cf->SearchContact(name);

            for(auto num:res){
                cout<< num <<" ";
            }
        }
    }
}