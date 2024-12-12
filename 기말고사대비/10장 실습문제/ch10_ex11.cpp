#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main(){
    vector <int> v;
    vector <int> :: iterator it;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (it=v.begin();it!=v.end();++it){
        int n= *it;
        n=n*2;
        *it = n;
    }
    it=v.begin();
    it++;
    it=v.erase(it);
    for(it=v.begin();it!=v.end();++it){
        cout<<*it<<' ';
    }
    cout<<endl;
}