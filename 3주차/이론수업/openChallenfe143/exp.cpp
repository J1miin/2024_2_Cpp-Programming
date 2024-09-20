#include <iostream>
using namespace std;
//class 구현
#include "exp.h"

Exp::Exp(int base, int exp): base(base), exp(exp){}
Exp::Exp(int base): base(base), exp(1){}
Exp::Exp():base(1), exp(1){}

int Exp::getValue(){
    int result =base;
    for (int i=0; i<exp;++i){
        result*=base;
    }
    return result;
}

int Exp::getExp(){
    return exp;
}
int Exp::getBase(){
    return base;
}

bool Exp::equals(Exp b){
    if (getValue() == b.getValue()){
        return true;
    }else{
        return false;
    }
}
