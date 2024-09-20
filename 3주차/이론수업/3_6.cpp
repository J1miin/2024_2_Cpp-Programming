#include <iostream>
using namespace std;
class Rectangle{
    public:
    int x, y;
    Rectangle();
    ~Rectangle(); //소멸자
    Rectangle(int x);
    Rectangle(int x, int y);
    bool isSquare();
};

Rectangle::Rectangle(){
    x=y=1;
}

Rectangle::Rectangle(int a, int b){
    x=a;
    y=b;
}

Rectangle::Rectangle(int a){
    x=a;
    y=a;
}

bool Rectangle::isSquare(){
    if (x==y){
        return true;
    }else {
        return false;
    }
}

int main(){
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout<<"rect1 is 정사각형"<< endl;
    if(rect2.isSquare()) cout<<"rect2 is 정사각형"<< endl;
    if(rect3.isSquare()) cout<<"rect3 is 정사각형"<< endl;
}