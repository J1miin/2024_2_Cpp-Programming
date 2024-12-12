#include <iostream>
#include <string>
using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) {
		mem = new char[size];
	}
	BaseMemory(int capacity, char* x, int size) {
		mem = new char[capacity];
		for (int i = 0; i < size; ++i) {
			mem[i] = x[i];
		}
	}
	char get(int idx) {
		return mem[idx];
	}
	void put(int idx , char value) {
		mem[idx] = value;
	}
};

class ROM : public BaseMemory {
	int usedSize = 0;
public:
	ROM(int capacity, char* x, int size) : BaseMemory(capacity, x, size) {
		usedSize = size;
	}
	char read(int i) {
		return get(i);
	}
};

class RAM : public BaseMemory {
public:
	RAM(int capacity) : BaseMemory(capacity) {}
	void write(int index, char value) {
		put(index, value);
	}
	char read(int i) {
		return get(i);
	}
};

int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; ++i) {
		mainMemory.write(i, biosROM.read(i));
	}
	for (int i = 0; i < 5; ++i) {
		cout << mainMemory.read(i);
	}
}