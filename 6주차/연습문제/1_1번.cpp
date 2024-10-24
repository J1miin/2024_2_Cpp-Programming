#include <iostream>
using namespace std;

int add(int a[], int b){
    int iResult = 0;
    for (int i=0; i<5 ; ++i){
        iResult+= a[i];
    }
    return iResult;
}
int add(int a[], int b, int c[]){
    int iResult = 0;
    for (int i=0; i<5 ; ++i){
        iResult+= a[i]+c[i];
    }
    return iResult;
}

int main(){
    int a[] ={1,2,3,4,5};
    int b[] = {6,7,8,9,10};
    int c = add(a,5);
    int d = add(a,5,b);
    cout<<c<<endl;
    cout<<d<<endl;
    return 0;
}