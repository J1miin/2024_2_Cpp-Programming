#include <iostream>
#include <string>
using namespace std;
class Printer {
private:
	string model, manufacturer;
	int printedCount, availableCount;

public:
	Printer(string model, string manufcturer, int printedCnt, int availableCount) {
		this->model = model;
		this->manufacturer = manufcturer;
		this->printedCount = printedCnt;
		this->availableCount = availableCount;

	}
	bool print(int pages) {
		if (availableCount < pages) {
			return false;
		}
		printedCount += pages;
		availableCount -= pages;
		return true;
	}
	void showInfo() {
		cout << model << ", " << manufacturer << ", 남은 종이 : " << availableCount << ", ";
	}
};
//InkJetPritner 
class InkJetPrinter : public Printer {
private:
	int availableInk=10;
public:
	InkJetPrinter(string model, string manufcturer , int availableCount ,int printedCnt = 0) : Printer(model, manufcturer, printedCnt, availableCount) {}


	bool printInkJet(int pages) {
		bool res = print(pages);
		if (res == true) {
			if (availableInk < pages) {
				cout << "잉크가 부족하여 출력할 수 없습니다." << endl;
				return false;
			}
			availableInk -= pages;
			return true;
		}else {
			cout << "용지가 부족하여 출력할 수 없스니다." << endl;
			return false;
		}
	}

	void showStatus() {
		cout << "잉크젯 : ";
		showInfo();
		cout << "남은 잉크 " << availableInk;
	}
};

//LaserPrinter
class LaserPrinter : public Printer {
private:
	int availabeToner=20;
public:
	LaserPrinter(string model, string manufcturer, int availableCount, int printedCnt = 0) : Printer(model, manufcturer, printedCnt, availableCount) {}
	void showStatus() {
		cout << "레이저 : ";
		showInfo();
		cout << "남은 토너 " << availabeToner;
	}
	bool printLaser(int pages) {
		bool res = print(pages);
		if (res == true) {
			if (availabeToner < pages) {
				cout << "토너가 부족하여 출력할 수 없습니다." << endl;
				return false;
			}
			availabeToner -= pages;
			return true;
		}
		else {
			cout << "용지가 부족하여 출력할 수 없습니다." << endl;
			return false;
		}
	}


};
int main() {
	InkJetPrinter inkPrinter("Officejet V40", "HP", 5);
	LaserPrinter laserPrinter("SCX-6x45", "삼성전자",3);
	cout << "현재 작동 중인 2대의 프린터는 다음과 같다." << endl;
	inkPrinter.showStatus();
	cout << endl;
	laserPrinter.showStatus();
	//

	int iSelect, iPages;
	char cAnswer;
	while (true) {
		cout << endl<<"프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> iSelect >> iPages;
		if (iSelect == 1) {
			bool res = inkPrinter.printInkJet(iPages);
			if (res == true) {
				cout << "프린트 하였습니다." << endl;
			}
		}
		else if (iSelect == 2) {
			bool res = laserPrinter.printLaser(iPages);
			if (res == true) {
				cout << "프린트 하였습니다."<<endl;
			}
		}
		else {
			cout << "잘못된 입력입니다." << endl;
		}
		inkPrinter.showStatus();
		cout << endl;
		laserPrinter.showStatus();
		cout << endl;
		cout << "계속 프린트하시겠습니까?(y/n)>>";
		cin >> cAnswer;
		cout << endl;
		if (cAnswer == 'y') {
			continue;
		}
		else {
			break;
		}
		
	}
}