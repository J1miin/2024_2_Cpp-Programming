#include <iostream>
#include <string>
using namespace std;

class BaseArray {
	int capacity;
	int * p;
	
protected : 
	BaseArray(int capacity=100) {
		this->capacity = capacity; 
		p = new int [capacity];
	}
	~BaseArray() { delete [] p; }
	void put(int idx, int val) { 
		p[idx] = val;
	}
	int get(int idx) { 
		return p[idx]; 
	}
	int getCapacity() { 
		return capacity; 
	}
};

class MyStack : public BaseArray {
	int top;
public :
	MyStack(int size) : BaseArray(size){ 
		top = 0; 
	}
	void push(int n){ 
		put(top, n);
		top++; 
	}
	int capacity() { 
		return getCapacity();
	}
	int length() { 
		return top; 
	}
	int pop() { 
		top--; 
		return get(top); 
	}
};

int main() {
	MyStack myStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for(int i=0; i<5; i++) {
		cin >> n;
		myStack.push(n);
	}
	cout << "스택용량:" << myStack.capacity() << ", 스택크기:" << myStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while(myStack.length() != 0 ) {
		cout << myStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << myStack.length() << endl;
}