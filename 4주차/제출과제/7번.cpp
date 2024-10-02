#include <iostream>
using namespace std;
class Circle{
    int radius;
    public :
    void setRadius(int radius);
    double getArea();
};

void Circle::setRadius(int radius){
    this->radius = radius;
}

double Circle::getArea(){
    double area = 1;
    area = this->radius * this->radius * 3.14;
    return area;
}
int main(){
    int inputRadius;
    int cntCircle = 0; //100보다 면적이 큰 원을 카운트하는 변수
    Circle *pCircle = new Circle[3];
    for (int i=0;i<3;++i){
        cout<< "원 "<<(i+1)<<"의 반지름 >>";
        cin >> inputRadius;
        pCircle[i].setRadius(inputRadius);
        if (pCircle[i].getArea()>100){
            cntCircle++;
        }
    }  
    cout<<"면적이 100보다 큰 원은 "<<cntCircle<<"개 입니다."<<endl;
}