//�迭�� �����ϴ� ���׸� mcopy() �Լ� ����� ����
#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[], T2 dst[], int n) {
	for (int i = 0; i < n; ++i) {
		dst[i] = (T2)src[i];
	}
}

int main() {
	int x[] = { 1,2,3,4,5 };
	double d[5];
	char c[5] = { 'a','b','c','d','e' }, e[5];

	mcopy(x, d, 5);
	mcopy(c, e, 5);

	for (int i = 0; i < 5; ++i) {
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		cout << e[i] << " ";
	}
	cout << endl;
}