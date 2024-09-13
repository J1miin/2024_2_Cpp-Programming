#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char cName[50];
    char cAddress[50];
    int iAge ;
    
    cout<<"이름은? ";
    cin.getline(cName,50,'\n');
    
    cout<<"주소는? ";
    cin.getline(cAddress,50,'\n');
    
    cout<<"나이는? ";
    cin>>iAge;
    
    cout<<cName<<","<<cAddress<<","<<iAge;
    return 0;
}