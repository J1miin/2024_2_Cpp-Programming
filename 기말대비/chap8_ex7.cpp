#include <iostream>
#include <string>
using namespace std;

class Adder{
protected:
    int add(int a, int b){
        return a+b;
    }
};

class Subtractor{
protected:
    int sub(int a, int b){
        return a-b;
    }
};

class Calculator : public Adder, public Subtractor{
public:
    int calc(char op, int a, int b);
};

int Calculator :: calc(char op, int a, int b){
    int res = 0;
    if (op=='+'){
        res = add(a,b);
    }
    if (op=='-'){
        res = sub(a,b);
    }
    return res;
}

int main(){
    Calculator cCalulator;
    cout<<"2+3="<<cCalulator.calc('+',2,3)<<endl;
}