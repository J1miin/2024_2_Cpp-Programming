#include <iostream>
#include <map>
#include <string>
#include <typeinfo>  
using namespace std;

void program() {
    map<string, string> WHO;
    cout << "***** 암호관리 프로그램 WHO를 시작합니다 *****" << endl;
    while (true) {
        cout << "삽입:1, 검사:2, 종료:3 >> ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "이름 암호 >> ";
            string name, password;
            cin >> name >> password;
            WHO.insert(make_pair(name, password));
        }
        else if (choice == 2) {
            cout << "이름? ";
            string name;
            cin >> name;

            if (WHO.find(name) == WHO.end()) {
                cout << "이름이 등록되지 않았습니다." << endl;
                continue;
            }

            while (true) {
                cout << "암호? ";
                string password;
                cin >> password;

                if (WHO[name] == password) {
                    cout << "통과!!" << endl;
                    break;
                }
                else {
                    cout << "실패~~" << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "입력 오류" << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue;
        }
    }
}

int main() {
    program();
}
