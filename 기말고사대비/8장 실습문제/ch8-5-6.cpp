#include <iostream>
#include <string>
using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() {
		delete[] mem;
	}

	void put(int index, int val) {
		mem[index] = val;
	}
	int get(int index) { return mem[index];}
	int getCapacity() { return capacity; }
};

class MyQueue : protected BaseArray {
private:
	int idx, deIdx, qSize;
public:
	MyQueue(int size) : BaseArray(size), idx(0), deIdx(0), qSize(0) {}
	void enqueue(int n) {
		if (qSize < getCapacity()) {
			put(idx, n);
			idx++;
			qSize++;
		}
		else {
			cout << "큐가 가득 찼습니다!" << endl;
		}
	}
	int capacity() {
		return getCapacity();
	}
	int length() {
		return qSize;
	}
	int dequeue() {
		if (qSize == 0) {
			cout << "큐가 비어 있습니다!" << endl;
			return -1; // 빈 큐에서 값을 제거하려 할 때
		}
		int res = get(deIdx);
		deIdx++;
		qSize--;
		return res;
	}
};

class MyStack : protected BaseArray {
private:
	int idx, sSize;
public:
	MyStack(int capacity) : BaseArray(capacity), idx(0), sSize(0) {}
	void push(int n) {
		if (sSize < getCapacity()) {
			put(idx, n);
			idx++;
			sSize++;
		}
		else {
			cout << "스택이 가득 찼습니다!" << endl;
		}
	}
	int capacity() {
		return getCapacity();
	}
	int length() {
		return sSize;
	}
	int pop() {
		if (sSize == 0) {
			cout << "스택이 비어 있습니다!" << endl;
			return -1; 
		}
		idx--;
		int res = get(idx);
		sSize--;
		return res;
	}
};
int main() {
	//5번
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하세요 >>";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다 >>";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << " ";
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;

	//6번
	MyStack mStack(100);
	cout << "스택에 삽입할 5개의 정수를 입력하세요 >>";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택의 용량 : " << mStack.capacity() << ", 스택의 크기 : " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다 >> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << " ";
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}
