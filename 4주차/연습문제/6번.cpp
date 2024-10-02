#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cout<< "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)"<< endl<<">>";
    getline(cin,str,'\n');
    if (str.compare("eixt")==1){
        return 0;
    }else{
        int len =str.length();
        for (int i=0;i<len;++i){
            cout<<str[len-i];
        }
    }
}