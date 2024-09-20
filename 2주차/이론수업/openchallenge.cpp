//pg 83 
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char answer1[4];
    char answer2[4];
    cout<<"가위 바위 보 게임을 합니다. 가위, 바위, 보 중에서 입력하세요.\n";
    
    cout<<"로미오>>";
    cin>>answer1;
    
    cout<<"줄리엣>>";
    cin>>answer2;

    if (strcmp(answer1,"가위")){
        if (strcmp(answer2,"가위")){
            cout<<"비김1"<<answer2;
        }else if (strcmp(answer2,"바위")){
            cout<<"줄리엣이 이김";
        }
        else {
            cout<<"로미오가 이김";
        }
    }else if (strcmp(answer1,"바위")){
        if (strcmp(answer2,"가위")){
            cout<<"로미오가 이김";
        }else if (strcmp(answer2,"바위")){
            cout<<"비김2";
        }
        else {
            cout<<"줄리엣이 이김";
        }
    }else{ //보
        if (strcmp(answer2,"가위")){
            cout<<"줄리엣이 이김";
        }else if (strcmp(answer2,"바위")){
            cout<<"로미오가 이김";
        }
        else {
            cout<<"비김3";
        }
    }
}