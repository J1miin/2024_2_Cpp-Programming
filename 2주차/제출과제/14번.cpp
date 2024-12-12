#include <iostream>
using namespace std;

int main(){
    int iHowmany, totalIncome;
    int costArr[3]={2000, 2300, 2500};
    totalIncome=0;
    cout<<"에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다."<<endl;

    while(true){
        if (totalIncome>=20000){
            cout<<"오늘 "<<totalIncome<<"원을 판매하여 카페를 닫습니다. 내일 봐요~~";
            break;
        }else{
            char cInputMenu[30];
            cout<<"주문>>";
            cin>>cInputMenu>>iHowmany;
            if (strcmp(cInputMenu,"에스프레소")==0){
                cout<<costArr[0]*iHowmany<<"원 입니다. 맛있게 드세요."<<endl;
                totalIncome+=costArr[0]*iHowmany;
            }else if (strcmp(cInputMenu,"아메리카노")==0){
                cout<<costArr[1]*iHowmany<<"원 입니다. 맛있게 드세요."<<endl;
                totalIncome+=costArr[1]*iHowmany;
            }else if (strcmp(cInputMenu,"카푸치노")==0){
                cout<<costArr[2]*iHowmany<<"원 입니다. 맛있게 드세요."<<endl;
                totalIncome+=costArr[2]*iHowmany;
            }
        }
        
    }
    


    return 0;
}