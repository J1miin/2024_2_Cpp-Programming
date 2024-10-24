#include <iostream>
using namespace std;

class ArrayUtility {
public:
    static void inToDouble(int source[], double dest [], int size);
    static void doubleTolnt(double source[], int dest[], int size);
};

void ArrayUtility::inToDouble(int source[], double dest [], int size){
    for (int i=0;i<size;++i){
        dest[i]=(double)source[i];
    }
}
void ArrayUtility::doubleTolnt(double source[], int dest[], int size){
    for (int i=0;i<size;++i){
        dest[i]=(int)source[i];
    }
}

int main(){
    int x[]= {1,2,3,4,5};
    double y[5];
    double z[] = {9.9, 8.8, 7.7, 6.6, 5.6};

    ArrayUtility::inToDouble(x,y,5);
    for(int i =0; i<5; ++i){
        cout<<y[i]<<' ';}
    cout<<endl;

    ArrayUtility::doubleTolnt(z,x,5);
    for(int i=0; i<5; i++) cout << x[i] << ' ';
    cout << endl;

}