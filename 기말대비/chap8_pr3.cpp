/*
3. 다음 main() 함수가 실행되도록 Point 클래스를 상속받은 ColorPoint 클래스를 작성하고,
전체 프로그램을 완성하라.
*/
#include <iostream>
#include <string>
using namespace std;

class Point{
    int x,y;

public:
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    void setPoint (int x, int y){
        this->x = x;
        this->y = y;
    }   
    int getPointX(){
        return x;
    }      
    int getPointY(){
        return y;
    }
};

class ColorPoint : public Point{
    string color;
public:
    ColorPoint(int x, int y, string sColor): Point(x, y) {
            this->color = sColor;
    }
    void setColor(string sColor){
        this->color = sColor;
    }
    void show(){
        cout<<color<<"색으로 ("<<getPointX()<<","<<getPointY()<<")에 위치한 점입니다."<<endl;
    }
};

int main(){
    ColorPoint cp(5,5,"RED");
    cp.setPoint(10,20);
    cp.setColor("BLUE");
    cp.show();
}