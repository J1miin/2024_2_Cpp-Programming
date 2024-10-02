#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player{
    string name;
    public:
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
};

class GamblingGame{
    Player *pPlayer = new Player[2];
public:
    GamblingGame(){
        cout<<"***** 겜블링 게임을 시작합니다 *****"<<endl;
    };
    int printRandomNumber();
    void startGame();
    void nameSet();
    ~GamblingGame() {delete []pPlayer;}
};

//선수 등록
void GamblingGame::nameSet(){
    string sName;
    cout<<"첫 번째 선수 이름>>";
    cin>>sName;
    pPlayer[0].setName(sName);

    cout<<"두 번째 선수 이름>>";
    cin>>sName;
    cin.ignore();
    pPlayer[1].setName(sName);
}

//랜덤숫자 출력
int GamblingGame::printRandomNumber(){
    srand((unsigned)time(0));
    int n[3];
    for (int i=0;i<3;++i){
        n[i]= rand()%3;
        cout<<n[i]<<"  ";
    }
    
    if (n[0]==n[1]&& n[1]==n[2]){
        return 1;
    }
    return 0;    
}

void GamblingGame::startGame(){
    int i=1;
    int trackNum;
    while (true){
        trackNum=(i+1)%2;
        string startText;
        cout<<pPlayer[trackNum].getName()<<":";
        getline(cin, startText,'\n');
        
        if (startText.empty()){
            int result = printRandomNumber();
            if (result ==1){
                cout<<pPlayer[trackNum].getName()<<"님 승리!!"<<endl;
                break;
            }else{
                cout<<"아쉽군요!"<<endl;
            }
            i++;
        }else{
            cout<<"<Enter>를 치지 않으면 게임을 시작할 수 없습니다."<<endl;
        }
    }
}

int main(){
    GamblingGame game;
    game.nameSet();
    game.startGame();

}