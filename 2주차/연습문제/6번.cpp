#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char first[10], second[10];
    cout << "새 암호를 입력하세요 >> ";
    cin >> first ;
    cout << "새 암호를 다시 한 번 입력하세요 >>";
    cin >> second ; 

    if (strcmp(first,second)==0){
        cout << "같습니다";
    }else {
        cout << "같지 않습니다";
    }


    return 0;
}