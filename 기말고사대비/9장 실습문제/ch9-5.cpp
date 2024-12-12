#include <iostream>
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) {
		this->x = x;
		this->y = y;
	}
	virtual bool operation() = 0;
};
//AndGate
class ANDGate : public AbstractGate {
public:
	ANDGate (){}
	virtual bool operation() {
		if (x == true && y == true) {
			return true;
		}
		else {
			return false;
		}
	}
};
//OrGate
class ORGate : public AbstractGate {
public:
	ORGate(){}
	virtual bool operation() {
		if (x == false && y == false) {
			return false;
		}
		else {
			return true;
		}
	}
};
//XorGate
class XORGate : public AbstractGate {
public:
	XORGate(){}
	virtual bool operation() {
		if (x == true && y == false) {
			return true;
		}
		else if (x == false && y == true) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}