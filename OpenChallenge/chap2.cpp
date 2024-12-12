#include <iostream>
using namespace std;

int main(){
    string romio;
    string juliet;
    cout<< "가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요." << endl;
    cout<< "로미오>>" ;
    cin >> romio;
    cout<< "줄리엣>>" ;
    cin >> juliet ; 

    if (romio.compare(juliet)==0){ 
        //0이면 같다, 0보다 크면 juliet이 사전적으로 앞에 있다. 0보다 작으면 romio가 사전적으로 앞에 있다.
        cout<< "비겼습니다."<< endl;
    }else if (romio=="가위" && juliet =="바위"){
        cout<< "Juliet win"<< endl;
    }else if (romio=="가위" && juliet =="보"){
        cout<< "romio win"<< endl;
    }else if (romio=="바위" && juliet =="가위"){
        cout<< "romio win"<< endl;
    }else if (romio == "바위" && juliet == "보"){
        cout<< "juliet win"<< endl;
    }else if (romio == "보" && juliet == "가위"){
        cout<< "juliet win"<< endl;
    }else if (romio=="보" && juliet == "바위"){
        cout<< "romio win"<< endl;
    }else {
        cout<< "잘못된 입력입니다." << endl;
    }
    return 0;
}