#include <iostream>
#include <string.h>
using namespace std;

int main(){
    float fArr[5];
    float fMax =0;
    cout<<"5개의 실수를 입력하라>> ";
    cin>>fArr[0]>>fArr[1]>>fArr[2]>>fArr[3]>>fArr[4];
    for (int i=0; i<5; ++i){
        if (fArr[i] >= fMax){
            fMax = fArr[i];
        }
    }
    cout<<"제일 큰 수 = "<< fMax;
    return 0;
}