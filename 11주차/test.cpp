#include <iostream>
#include <string>
using namespace std;

int main (){
    int test;

    while(true){
        cout<<"값을 ㅇ입력해:";
        cin>>test;
        cout<<"값:"<<test<<endl;    
        cout<<"test"<<endl;
        if (test ==1 ){
            cout<<"test well done"<<endl;
        }else{
            cout<<"write again "<<endl;
            cin.clear(); // cin의 오류 플래그를 초기화
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼를 비움
            continue;
        }
    }
}
