#include <iostream>
#include <iomanip>
using namespace std;

class Ingredients {
protected:
    string name;
    int amount;
public:
    string getName() {
        return name;
    }
    int getAmount() {
        return amount;
    }
    void setAmount(int amount) {
        this->amount = amount;
    }
    bool subAmount(int amount) {
        if (this->amount < amount)
            return false;
        this->amount -= amount;
        return true;
    }
};

class Coffee : public Ingredients {
public:
    Coffee() {
        name = "Coffee";
        amount = 3;
    }
};

class Sugar : public Ingredients {
public:
    Sugar() {
        name = "Sugar";
        amount = 3;
    }
};

class Cream : public Ingredients {
public:
    Cream() {
        name = "Cream";
        amount = 3;
    }
};

class Water : public Ingredients {
public:
    Water() {
        name = "Water";
        amount = 3;
    }
};

class Cup : public Ingredients {
public:
    Cup() {
        name = "Cup";
        amount = 3;
    }
};

class Program {
    Ingredients* oArr[5];
public:
    Program() {
        cout << "----- 명품 커피 자판기 켭니다. -----" << endl;
        oArr[0] = new Coffee();
        oArr[1] = new Sugar();
        oArr[2] = new Cream();
        oArr[3] = new Water();
        oArr[4] = new Cup();
        showState();
        cout << endl;
    }

    ~Program() {
        for (int i = 0; i < 5; ++i) {
            delete oArr[i];
        }
    }

    void showState() {
        for (int i = 0; i < 5; ++i) {
            cout << setw(10) << oArr[i]->getName();
            for (int j = 0; j < oArr[i]->getAmount(); ++j)
                cout << "*";
            cout << endl;
        }
    }

    bool checkAndSubtract(int indices[], int size) {
        for (int i = 0; i < size; ++i) {
            if (!oArr[indices[i]]->subAmount(1)) {
                cout << "재료가 부족합니다." << endl << endl;
                return false;
            }
        }
        return true;
    }

    void start() {
        int menuNum;
        while (true) {
            showMenu();
            menuNum = selectMenu();

            if (menuNum == 3) { 
                for (int i = 0; i < 5; i++) {
                    oArr[i]->setAmount(3);
                }
                cout << "모든 통을 채웁니다~~" << endl;
                showState();
                cout << endl;
                continue;
            }
            else if (menuNum == 4) { 
                cout << "명품 커피 자판기 끕니다~~" << endl;
                exit(0);
            }

            int required[] = {0, 3, 4}; //커피랑 물 컵 확인하는 부분 
            if (!checkAndSubtract(required, 3)) {
                continue; 
            }

            switch (menuNum) {
                case 0: { 
                    if (!oArr[2]->subAmount(1)) { // 크림 체크
                        cout << "크림이 부족합니다." << endl << endl;
                        continue;
                    }
                    cout << "맛있는 보통 커피 나왔습니다~~" << endl;
                    break;
                }
                case 1: { 
                    if (!oArr[1]->subAmount(1)) { // 설탕 체크
                        cout << "설탕이 부족합니다." << endl << endl;
                        continue;
                    }
                    cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
                    break;
                }
                case 2: { 
                    cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
                    break;
                }
                default:
                    cout << "잘못 입력하셨습니다." << endl << endl;
                    break;
            }
            showState();
            cout << endl;
        }
    }

    void showMenu() {
        cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>> ";
    }

    int selectMenu() {
        int menuNum;
        cin >> menuNum;
        return menuNum;
    }
};

int main() {
    cout.setf(ios::left);
    Program c;
    c.start();
}
