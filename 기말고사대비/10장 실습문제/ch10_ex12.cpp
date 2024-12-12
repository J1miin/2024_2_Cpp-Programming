//making ko-en dictionary
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, string> dic;
    dic.insert(make_pair("love","사랑"));
    dic.insert(make_pair("apple","사과"));
    dic["cherry"]="체리";

    cout<<"저장된 단어 개수" << dic.size()<< endl;
    string eng;
    while (true){
        cout<<"write a word what you want to find >>";
        getline(cin,eng);
        if (eng=="exit"){
            break;
        }
        if(dic.find(eng)==dic.end()){
            cout<<"none"<<endl;
        }else{
            cout<<dic[eng]<<endl;
        }
    }
    cout<<"quit this program"<<endl;
}