#include<iostream>
#include <string>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
	virtual ~AbstractStack() {}
};

class Stack : public AbstractStack {
private:
	int iIdx, iCapacity, iSize;
	int* mem;
public:
	Stack() :AbstractStack() {
		iIdx = 0;
		iCapacity = 100;
		iSize = 3;
		mem = new int[iCapacity];
	}
	virtual bool push(int n) {
		if (iIdx >=3) {
			return false;
		}
		mem[iIdx] = n;
		++iIdx;
		return true;
	}
	virtual bool pop(int& n) {
		iIdx--;
		if (iIdx<=-1) {
			return false;
		}

		n = mem[iIdx];
		return true;
	}
	virtual int size() {
		return iIdx;
	}
	~Stack() {
		delete[] mem;
	}
};
int main() {
	Stack stack;
	for (int i = 0; i <5; ++i) {
		if (stack.push(i)) cout << "push 성공" << endl;
		else cout << "stack is full right now" << endl;
	}

	int n;
	for (int i = 0; i < 5; ++i) {
		if (stack.pop(n)) cout << "pop 성공" << n << endl;
		else cout << "stack is empty right now" << endl;
	}
	return 0;
}