#include <iostream>
using namespace std;
//class 구현
#include "Div.h"

void Div::setValue(int x, int y){
    a = x;
    b = y;
}

int Div::calculate(){
    if (b==0){
        return -1;
    }else{
        return a/b;
    }
}