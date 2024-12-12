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
			cout << "ť�� ���� á���ϴ�!" << endl;
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
			cout << "ť�� ��� �ֽ��ϴ�!" << endl;
			return -1; // �� ť���� ���� �����Ϸ� �� ��
		}
		int res = get(deIdx);
		deIdx++;
		qSize--;
		return res;
	}
};

int main() {
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��ϼ��� >>";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ� >>";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << " ";
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}
