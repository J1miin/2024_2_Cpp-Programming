#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("C:\\windows\\system.ini");
	int text;

	if (!fin) {
		cout << "파일을 열지 못했습니다.";
		return 0;
	}

	while ((text = fin.get()) != EOF) {
		if (isalpha(text)) {
			text = toupper(text);
		}
		cout << char(text);
	}

	return 0;
}