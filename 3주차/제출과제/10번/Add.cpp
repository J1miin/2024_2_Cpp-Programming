#include <iostream>
using namespace std;
//class 구현
#include "Add.h"

void Add::setValue(int x, int y){
    a = x;
    b = y;
}

int Add::calculate(){
    return a+b;
}