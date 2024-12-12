#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Word{
private :
    string sKor, sEng;
public:
    Word(string kr, string en){
        sKor = kr;
        sEng = en;
    }
    string getKr(){
        return sKor;
    }
    string getEn(){
        return sEng;
    }
};
class Start{

public:
    vector<Word> v ;
    Start(){
        Word w1 = Word("사랑","love");
        Word w2 = Word("사과","apple");
        Word w3 = Word("레몬","lemon");
        Word w4 = Word("친구","friend");
        Word w5 = Word("가족","family");
        
        v.push_back(w1);
        v.push_back(w2);
        v.push_back(w3);
        v.push_back(w4);
        v.push_back(w5);
    }

    void startGame(){
        cout<<"영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다."<<endl;
        while (true){
            int n = rand()%(v.size());
            string ans = v[n].getKr();
            
            cout<<v.at(n).getEn()<<"?"<<endl;
            int iAnsIdx = showEx(ans);
            cout<<":> ";
            int userAns;
            cin>>userAns;

            if (userAns < 1 || userAns > 4) {
                cout << "게임을 종료합니다." << endl;
                break;
            }

            if(userAns-1==iAnsIdx){
                cout<<"Excellent!!"<<endl;
            }else{
                cout<<"No..!"<<endl;
            }
        }
    }

    int showEx(string ansKr){
        vector<string> ansList;
        ansList.push_back(ansKr);
        
        //보기에 나올 단어 4개 먼저 선택해서 ansList 벡터에 넣기 
        while (ansList.size()<4){ //사지선다니까
            int n= rand()%v.size();
            string bogi = v[n].getKr();
            if (find(ansList.begin(), ansList.end(), bogi) == ansList.end()) {
                ansList.push_back(bogi);
            }
        } 

        for (int i=0;i<ansList.size();++i){
            int j=rand()%ansList.size();
            swap(ansList[i],ansList[j]);
        }

        int iAnswerIdx;
        for (int i=0;i<ansList.size();++i){
            cout << "(" << i + 1 << ") " << ansList[i] << " ";
            if (ansList[i] == ansKr) {
                iAnswerIdx = i;
            }
        }
        cout << endl;
        return iAnswerIdx;
    }
};

int main(){
    srand(static_cast<unsigned>(time(0)));
    Start startGame;
    startGame.startGame();   
}