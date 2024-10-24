#include <iostream>
using namespace std;
int big(int a=10, int b=10, int c=100){
    if (a<b && b<c){
        return b;
    }else if (a>b && a<c){
        return a;
    }else if (a>b && a>c){
        return c;
    }else if (a<b && b>c){
        return c;
    }
    return 0;
}

int main(){
    int x = big(3,5);
    int y = big(300,60);
    int z = big(30,60,50);
    cout<<x<<' '<<y<<' '<<z<<endl;   
}