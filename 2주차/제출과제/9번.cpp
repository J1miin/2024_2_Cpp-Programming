#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char cName[50];
    char cAddress[50];
    int iAge ;
    string c1,c2,c3;
    cout<<"이름은? ";
    // cin.getline(cName,50,'\n');
    getline(cin,c1);
    cout<<"주소는? ";
    //cin.getline(cAddress,50,'\n');
    getline(cin,c2);
    cout<<"나이는? ";
    //cin>>iAge;
    getline(cin,c3);
    //cout<<cName<<","<<cAddress<<","<<iAge;
    cout<<c1<<c2<<c3;
    return 0;
}