#include <iostream>
using namespace std;

//참조변수 이용하기
void half(double &n){
    n = n/2;
}

int main(){
    double n = 20;
    half(n);
    cout << n;
}