//위임생성자 실습 예제
//default가 타겟 생성자이고, 위임 생성자로 들어왔을 때 타겟 생성자로 작동하게 하는 것
#include <iostream>
using namespace std;

class Circle{
    public:
    int radius;
    Circle(); //위임 생성자
    Circle(int r); //타겟 생성자
    double getArea();
};

//위임 생성자 : Circle 기본 생성자가 수행되면 반지름 1로 해서 타겟 생성자 실행하겠다.
Circle::Circle() : Circle(1){}

Circle::Circle(int r){
    radius = r;
    cout<< "반지름 "<< radius << " 원 생성"<< endl;
}

double Circle::getArea(){
    return 3.14*radius*radius;
}

int main(){
    Circle donut;
    double area = donut.getArea();
    cout<< "donut 면적은 " << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적은 "<< area << endl;
}