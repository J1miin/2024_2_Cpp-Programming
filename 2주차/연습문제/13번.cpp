#include <iostream>
#include <string.h>
using namespace std;

int main(){
    cout<<"*****승리장에 오신 것을 환영합니다.*****"<<endl;
    while (true){
        int iInputMenu, iHowMany; 
        cout<<"짬뽕:1, 짜장:2, 군만두:3, 종료:4 >> ";
        cin >> iInputMenu;
        if (iInputMenu >=1 && iInputMenu <=3  ){
            cout<<"몇 인분?";
            cin >> iHowMany;
            
            if (iInputMenu==1) {
                cout<<"짬뽕 "<<iHowMany<<"인분 나왔습니다."<<endl;
            }else if (iInputMenu==2) {
                cout<<"짜장 "<<iHowMany<<"인분 나왔습니다."<<endl;
            }else if (iInputMenu==3) {
                cout<<"군만두 "<<iHowMany<<"인분 나왔습니다."<<endl;
            }
        }else if (iInputMenu==4) {
            cout<<"오늘 영업은 끝났습니다."<<endl;
            break;
        }else{
            cout<<"다시 주문하세요!!"<<endl;
        }
    }
    
    
    return 0;
}