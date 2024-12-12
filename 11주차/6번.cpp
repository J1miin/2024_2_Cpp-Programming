#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include<cstdlib>
using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retsize);

int main() {
    cout<<"정수 배열 {1,2,3,4}에서 정수 배열 {-3,4,10,1,2,3}을 뺍니다."<<endl;

	int x[] = { 1,2,3,4 };
	int y[] = { -3,5,10,1,2,3 };
	int retSize;
	
    int *p = remove(x, 4, y, 6, retSize);
	if(retSize==0){
        cout<<"모두 제거되어 리턴하는 배열이 없습니다."<<endl;
    }else {
        for (int i = 0; i < retSize; i++){
            cout << p[i] << " ";
        }
        cout << endl;
        delete []p;
    }
    cout << endl;
    
    cout <<"실수 배열 {1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9}에서"<<endl;
    cout <<"실수 배열 {3.5, 4.8, 1.0, 2.0, 3.0}을 뺍니다."<<endl;

    double x2[] = {1.0, 2.0, 3.2, 4.8, 5.0, 6.0, 7.0, 99.9};
	double y2[]={3.5, 4.8, 1.0, 2.0, 3.0};

    double *q = remove(x2,8,y2,5,retSize);
    if(retSize==0){
        cout<<"모두 제거되어 리턴하는 배열이 없습니다."<<endl;
    }else {
        for (int i = 0; i < retSize; i++){
            cout << q[i] << " ";
        }
        cout << endl;
        delete []q;
    }
    return 0;
}

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retsize) {
	retsize=0;
    T* q = new T[sizeSrc];
    for (int i = 0; i < sizeSrc; i++) {
        bool found = false;
        for (int j = 0; j < sizeMinus; j++) {
            if (src[i] == minus[j]) {
                found = true;
                break; 
            }
        }
        if (!found) { 
            q[retsize++] = src[i];
        }
    }
    return q;
}