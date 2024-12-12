#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class ColorPoint : protected Point {
	string color;
public:
	ColorPoint(int x=0, int y=0, string color="BLACK") : Point(x, y) {
		this->color = color; 
	}
	void setPoint(int x, int y) {
		move(x, y);
	}
	void setColor(string color) {
		this->color = color;
	}
	void show() {
		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
	}
};

int main() {
	//3번
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
	//4번
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp1(5, 5);
	cp1.setPoint(10, 20);
	cp1.setColor("BLUE");
	cp1.show();
}