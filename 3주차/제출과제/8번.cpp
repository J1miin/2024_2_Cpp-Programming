#include <iostream>
#include <string>
using namespace std;

class Integer{
    int num;
public:
    Integer(int n): num(n) {};
    Integer(string sNum) : num(stoi(sNum)){};

    int get(){return num;};
    int set(int n){num=n; return num;};
    int isEven(){
        if (this->num%2 ==0){
            return 1;
        }else{
            return 0;
        }
    };
};


int main(){
    Integer n(30);
    cout << n.get() << ' ';
    n.set(50);
    cout << n.get() << ' ';

    Integer m("300");
    cout<< m.get() << ' ';
    cout << m.isEven();
}


