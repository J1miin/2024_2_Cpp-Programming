#include <iostream>
#include <string>
#include "Add.h"
#include "Mul.h"
#include "Sub.h"
#include "Div.h"

int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;
	while (true) {
		cout << "두 정수와 연산자를 입력하세요>>";
		int x, y;
		char op;
		cin >> x >> y >> op;

		switch (op) {
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			if (d.calculate() != -1) {  // -1이 아닌 경우에만 출력
				cout << d.calculate() << endl;
			}else {
				cout<<"0으로 나눌 수 없습니다."<<endl;
			}
			break;
		default:
			break;
		}
	}

	return 0;
}