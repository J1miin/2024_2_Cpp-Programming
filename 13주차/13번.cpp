#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <cctype>
using namespace std;

int main(){
    string strA, strB;
    ifstream file;
    vector<string> v;
    file.open("words.txt");

    if(file.is_open()){
        cout << " . . . words.txt 파일 로딩 완료" <<endl;
    }
    else {
        cout<< "파일을 발견할 수 없습니다." <<endl;
        return 0;}

    while (!file.eof()) {
        getline(file, strA);
        v.push_back(strA);
    }
    file.close();
    
    cout << "검색을 시작합니다. 단어를 입력해 주세요." << endl;
    while (true) {
        int flag = 0;
        cout <<"단어>>";
        cin >> strB;
        if (strB == "exit") return 0;

        for (int i = 0; i < v.size(); i++) {
            // 맨 앞만 매칭하도록
            if (v[i].substr(0, strB.size()) == strB) {
                flag = 1;
                cout << v[i] << endl;
            }
        }
        if (flag == 0) cout << "발견할 수 없음" << endl;
    } 
    return  0;
}
