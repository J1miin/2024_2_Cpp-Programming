#include <iostream>
using namespace std;


class ArrayUtility2{
public:
    static int * concat(int s1[], int s2[], int size);
    static int * remove(int s1[], int s2[], int size, int&retsize);
};
int* ArrayUtility2::concat(int s1[], int s2[], int size){
    int *concatArr = new int[size*2];
    for (int i=0;i<size;++i){
        concatArr[i]=s1[i];
    }
    for (int i=0;i<size;++i){
        concatArr[i+size]=s2[i];
    }
    return concatArr;
}

int* ArrayUtility2::remove(int s1[], int s2[],int size, int&retsize){
    int * resultArr = new int[size*2];
    int cnt;
    for (int i=0; i<5;++i){
        cnt = 0;
        for (int j=0;j<5; ++j){
            if (s1[i]==s2[j]){
                cnt++;
            }
        }
        if (cnt==0){ //같지않을 떄
            resultArr[i]=s1[i];
            retsize++;
        }
    }
    return resultArr;
}

int main(){
    int x[5];
    int y[5];
    int size =5;
    int resultSize =0 ;
    cout<<"정수 5개를 입력하라. 배열 x에 삽입한다.>>";
    cin>>x[0]>>x[1]>>x[2]>>x[3]>>x[4];
    cout<<"정수 5개를 입력하라. 배열 y에 삽입한다.>>";
    cin>>y[0]>>y[1]>>y[2]>>y[3]>>y[4];

    cout<<"합친 정수 배열을 출력한다."<<endl;
    int * p =ArrayUtility2::concat(x,y,size);
    for (int i=0;i<2*size;++i){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    int * q = ArrayUtility2::remove(x,y,size,resultSize);
    cout<<"배열 x[]에서 y[]를 뺀 결과를 출력한다."<<" 개수는"<<resultSize<<endl;
    for (int i=0;i<resultSize;++i){
        cout<<q[i]<<' ';
    }

    delete[] p;
    delete[] q;
    return 0;
}