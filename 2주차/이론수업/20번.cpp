#include <iostream>
using namespace std;

int main(){
    for (int n=0;n<4;n++){
        for (int i=0; i<n+1 ;++i){
            cout<<"*";
        }
        cout<<"\n";
    }
}