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
		cout << model << ", " << manufacturer << ", ���� ���� : " << availableCount << ", ";
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
				cout << "��ũ�� �����Ͽ� ����� �� �����ϴ�." << endl;
				return false;
			}
			availableInk -= pages;
			return true;
		}else {
			cout << "������ �����Ͽ� ����� �� �����ϴ�." << endl;
			return false;
		}
	}

	void showStatus() {
		cout << "��ũ�� : ";
		showInfo();
		cout << "���� ��ũ " << availableInk;
	}
};

//LaserPrinter
class LaserPrinter : public Printer {
private:
	int availabeToner=20;
public:
	LaserPrinter(string model, string manufcturer, int availableCount, int printedCnt = 0) : Printer(model, manufcturer, printedCnt, availableCount) {}
	void showStatus() {
		cout << "������ : ";
		showInfo();
		cout << "���� ��� " << availabeToner;
	}
	bool printLaser(int pages) {
		bool res = print(pages);
		if (res == true) {
			if (availabeToner < pages) {
				cout << "��ʰ� �����Ͽ� ����� �� �����ϴ�." << endl;
				return false;
			}
			availabeToner -= pages;
			return true;
		}
		else {
			cout << "������ �����Ͽ� ����� �� �����ϴ�." << endl;
			return false;
		}
	}


};
int main() {
	InkJetPrinter inkPrinter("Officejet V40", "HP", 5);
	LaserPrinter laserPrinter("SCX-6x45", "�Ｚ����",3);
	cout << "���� �۵� ���� 2���� �����ʹ� ������ ����." << endl;
	inkPrinter.showStatus();
	cout << endl;
	laserPrinter.showStatus();
	//

	int iSelect, iPages;
	char cAnswer;
	while (true) {
		cout << endl<<"������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> iSelect >> iPages;
		if (iSelect == 1) {
			bool res = inkPrinter.printInkJet(iPages);
			if (res == true) {
				cout << "����Ʈ �Ͽ����ϴ�." << endl;
			}
		}
		else if (iSelect == 2) {
			bool res = laserPrinter.printLaser(iPages);
			if (res == true) {
				cout << "����Ʈ �Ͽ����ϴ�."<<endl;
			}
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		inkPrinter.showStatus();
		cout << endl;
		laserPrinter.showStatus();
		cout << endl;
		cout << "��� ����Ʈ�Ͻðڽ��ϱ�?(y/n)>>";
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