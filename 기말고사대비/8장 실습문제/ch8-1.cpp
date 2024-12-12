#include <iostream>
#include <string>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	int getRadius() { return radius; }
	void setRadius(int radius){
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

class NamedCircle : public Circle {
	string name;
	static double iMax;
	static int iMaxIdx;
public:
	NamedCircle(int iRadius, string name) : Circle(iRadius) {
		this->name = name;
	}
	NamedCircle(int iRadius = 1) :Circle(iRadius) {}
	void show() {
		cout << "�������� " << getRadius() << "�� " << name << endl;
	}
	void setCircle(int iRadius, string name) {
		setRadius(iRadius);
		this->name = name;
	}
	void maxArea(int i) {
		if (iMax <= getArea()) {
			iMax = getArea();
			iMaxIdx = i;
		}
	}
	string getName() {
		return this->name;
	}
	static int getMaxIdx() {
		return iMaxIdx;
	}
};
int NamedCircle :: iMaxIdx = 0;
double NamedCircle::iMax = 0.0;

int main() {
	//1��
	NamedCircle waffle(3, "waffle");
	waffle.show();
	//2��
	NamedCircle pizza[5];
	string sName;
	int iRadius;
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << i << ">>";
		cin >> iRadius>>sName;
		pizza[i].setCircle(iRadius, sName);
		pizza[i].maxArea(i);
	}
	cout << "���� ������ ū ���ڴ� " << pizza[NamedCircle::getMaxIdx()].getName() << "�Դϴ�." << endl;

}