#include <iostream>
using namespace std;

class Stack {
    int stack[10];
    int top;
public: 
    Stack(){top = 0;}; //생성자
    Stack& operator<< (int iNum){
        stack[top] = iNum; 
        top ++;
        return *this;
    }
    bool operator! (){
        if (top==0){
            return true;
        }
        return false;
    }
    Stack& operator>> (int& iPopNum){
        iPopNum = stack[top-1];
        top--;
        return *this;
    }

};


int main(){
    Stack stack;
    stack << 3 << 5 << 10;
    while (true){
        if (!stack) break;
        int x;
        stack >> x;
        cout<< x <<' ';
    }
    cout << endl;
    return 0;
}