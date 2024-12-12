#include <iostream>
using namespace std;

class Histogram {
    string song;
public :
    Histogram(string song){
        this->song = song;
    }
    //문자열 연산자 중복 함수
    Histogram& operator<<(string s1){
        this->song += s1;
        return *this;
    }
    //문자char 연산자 중복 함수
    Histogram& operator<<(char c1){
        this->song += c1;
        return *this;
    }
    void operator!();
};

void Histogram :: operator!(){
    int iCnt = 0;
    int iLenOfstring = this->song.length(); //주의 문자열 길이 세는 방법
    int iArr[26]={0,}; //알파벳 카운트 배열 
    char c ;
    for (int i=0;i<iLenOfstring;++i){
        c=song[i];
        if (isalpha(song[i])){
            c = tolower(song[i]);
        }
        iArr[c - 'a']++; //문자 순서대로 저장하기 위함
        iCnt++;
    }
    //출력
    cout<< song <<endl;
    cout<<"총 알파벳 수 "<< iCnt << endl;
    //a-z 출력 by 아스키코드
    char x;
    for (int i=0;i<26;++i){
        x=97+i;
        cout<< (x) <<": ";
        //*찍기
        for (int j=0;j<iArr[i];++j){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
    song << "falling" << " in love with you."<< " - by";
    song << 'k' << 'i' << 't';
    !song; //히스토그램 그리기
    return 0;
}