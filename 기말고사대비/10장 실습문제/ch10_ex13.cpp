#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector <int> v;
    cout<<"write 5 integers >>";
    for (int i=0;i<5;++i){
        int n;
        cin>>n;
        v.push_back(n);
    }
    reverse(v.begin(),v.end());
    vector<int> :: iterator it;
    for(it=v.begin();it!=v.end();++it){
        cout<<*it<<' ';
    }
    cout<<endl;
}

