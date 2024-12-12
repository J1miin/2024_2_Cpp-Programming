#include <iostream>
using namespace std;


int get(){
    const char *fault = "input fault 예외 발생, 계산할 수 없음";
    int result =0;
    cout<<"0~9 사이의 정수 입력 >> ";
    cin>>result;
    if(result >=0 && result<=9){
        result = result;
    }else{throw fault;}
    return result;
};

void start(){
   while (true){
        try{
            int iInput1, iInput2;
            iInput1 = get();
            iInput2 = get();
            cout<<iInput1<<"x"<<iInput2<<"="<<iInput1*iInput2<<endl;
        }catch(const char *s){
            cout<<s<<endl;
        }
        
   } 
} 

int main(){
    start();
}