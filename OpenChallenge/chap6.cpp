#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Person{
    string sName;
    int iAnswer;
public:
    Person(string sName){
        this->sName = sName;
    }
    string getName(){
        return sName;
    }
    int setAnswer(){
        cin>>this->iAnswer;
        return iAnswer;
    }
};

class UpAndDownGame{
public :
    static int iAnswer;
    static int iMin;
    static int iMax;
    //랜덤 숫자 만들기
    static int makeRandNum(){
        srand((unsigned)time(0)); //랜덤함수 실행
        iAnswer = rand();
        iAnswer = iAnswer%100; //n=0~99사이 정수
        return iAnswer;
    }
    //숫자 검사 후 min, max 업데이트 하기
    static bool checkResult(int iInput){
        bool result = false;
        if (iInput == iAnswer){
            result = true;
        }else if(iInput<iAnswer) {
            iMin = iInput;
        }else {
            iMax = iInput;
        }
        return result;
    }
    //사람 바뀔 때마다 입력 처리하는 함수 
    static bool playTurn(Person& player){
        bool result = false;
        cout<<player.getName()<<">>";
        if (checkResult(player.setAnswer())==true){
            cout<<player.getName()<<"가 이겼습니다!!"<<endl;
            result = true;
        }else{
            cout<<"답은 "<<iMin<<"과 "<<iMax<<"사이에 있습니다."<<endl;
        }
        return result;
    }   
    static void startGame(){
        cout<<"Up & Down 게임을 시작합니다."<<endl;
        makeRandNum();
        iMin=0;
        iMax=100;

        Person player[2] = {Person("김인수"), Person("오인경")};
        cout<<"답은 0과 99사이에 있습니다."<<endl;
        
        while (true){
            for (int i=0;i<2;++i){
                if (playTurn(player[i])==true){
                    return;
                }   
            } 
        }
    }
};

// static 멤버 변수는 외부 전역에 선언 필수!! 이 때 static은 안쓴다.
int UpAndDownGame :: iAnswer; 
int UpAndDownGame :: iMin;
int UpAndDownGame :: iMax;

int main(){
    UpAndDownGame :: startGame();
}