#include <iostream>
#include <string>
using namespace std;

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() { }
	void paint() { draw(); }
	Shape* add(Shape* p) { 
        this->next = p; 
        return p; 
    }
	Shape* getNext() { return next; }
	void setNext(Shape* p) { next = p; }
};

// 원
class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

// 사각형
class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

// 선
class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class UI {
public:
	static int mainMenu() {
		int iMenu;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> iMenu;
		return iMenu;
	}
	static int insertMenu() {
		int iSelect;
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> iSelect;
		return iSelect;
	}
	static int delMenu() {
		int iSelect;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> iSelect;
		return iSelect;
	}
};

class GraphicEditor {
	Shape *pStart;
	Shape *pLast;
	int iCnt;
public:
	GraphicEditor() { 
        pStart = NULL; 
        iCnt = 0; 
    }

	void create(int num) {
        if (num == 1){
            if (iCnt == 0) {
				pStart = new Line();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Line());
			iCnt++;
        } else if (num == 2){
			if (iCnt == 0) {
				pStart = new Circle();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Circle());
			iCnt++;
        } else if (num == 3){
            if (iCnt == 0) {
				pStart = new Rect();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Rect());
			iCnt++;
        }
	}

	void deleteMenu(int num) {
		Shape *p = pStart;
		Shape *del = pStart;

		if (num < iCnt) {
			for (int i = 0; i < num; i++) {
				p = del;
				del = del->getNext();
			}
			if (num == 0)
				pStart = p->getNext();
			else
				p->setNext(del->getNext());
			iCnt--;
			if (iCnt == 1) pLast = pStart;
			delete del;

		} else {
			cout << "인덱스 오류." << endl;
		}
	}

	void call() {
		bool exit = true;
		cout << "그래픽 에디터입니다." << endl;
		while (exit) {
			int menu = UI::mainMenu();
			if (menu == 1) {
				create(UI::insertMenu());
			} else if (menu == 2) {
				deleteMenu(UI::delMenu());
			} else if (menu == 3) {
				Shape* p = pStart;
				for (int i = 0; i < iCnt; i++) {
					cout << i << ": "; p->paint();
					p = p->getNext();
				}
			} else if (menu == 4) {
				exit = false;
			}
		}
	}
};

int main() {
	GraphicEditor* editor = new GraphicEditor;
	editor->call();
	delete editor;
}
