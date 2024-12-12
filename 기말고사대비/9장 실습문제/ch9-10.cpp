#include <iostream>
using namespace std;
class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() {
		next = NULL;
	}
	virtual ~Shape(){}
	void paint() {
		draw();
	}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	Shape* getNext() { return next; }
	void setNext(Shape* p) {
		this->next = p;

	}
};
//��
class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};
//�簢��
class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rect" << endl;
	}
};
//��
class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

////////////////
//UI
class UI {
public:
	static int mainMenu() {
		int iMenu;
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		cin >> iMenu;
		return iMenu;
	}
	static int insertMenu() {
		int iSelect;
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> iSelect;
		return iSelect;
	}
	static int delMenu() {
		int iSelect;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
		cin >> iSelect;
		return iSelect;
	}
};
////////////////
//GraphicEditor 
class GraphicEditor {
private:
	Shape* pStart;
	Shape* pLast;
	int iCnt;
public:
	GraphicEditor() {
		pStart = NULL;
		pLast = NULL;
		iCnt = 0;
	}
	void create(int num) {
		if (num == 1) {
			if (iCnt == 0) {
				pStart = new Line();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Line());
			iCnt++;
		}
		else if (num == 2) {
			if (iCnt == 0) {
				pStart = new Circle();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Circle());
			iCnt++;
		}
		else if (num == 3) {
			if (iCnt == 0) {
				pStart = new Rect();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Rect());
			iCnt++;
		}
	}

	void delShape(int num) {
		Shape* p = pStart;
		Shape* del = pStart;

		if (num<iCnt){
			if (num == 0) {//ù��° ���Ҷ�� �׳� pStart�� �ι�°�� �Ű��ָ� ��
				pStart = pStart->getNext();
			}
			else {
				for (int i = 0; i < num; ++i) {
					p = del;
					del = del->getNext();
				}
				p->setNext(del->getNext());
			}
			iCnt--;
			delete del;
		}
		else {
			cout << "index fault" << endl;
		}
	}


	void start() {
		bool exit = true;
		cout << "�׷��� �������Դϴ�." << endl;
		while (exit) {
			int menu = UI::mainMenu();
			if (menu == 1) {
				create(UI::insertMenu());
			}
			else if (menu == 2) {
				delShape(UI::delMenu());
			}
			else if (menu == 3) {
				Shape* p = pStart;
				for (int i = 0; i < iCnt; i++) {
					cout << iCnt<<" i: "<<i << ": "; p->paint();
					p = p->getNext();
				}
			}
			else if (menu == 4) {
				exit = false;
			}
		}
	}
};

int main() {
	GraphicEditor* editor = new GraphicEditor;
	editor->start();
	delete editor;
}