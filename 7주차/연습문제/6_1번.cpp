#include <iostream>
using namespace std;
class Matrix{
    int arr[4];
    public :
    Matrix(int a=0, int b=0, int c=0, int d=0){
        arr[0]=a;
        arr[1]=b;
        arr[2]=c;
        arr[3]=d;
    }
    void show(){
        cout<< "Matrix = {";
        for (int i=0;i<4;++i){ 
            cout<< arr[i] << " " ;
        }
        cout<<"}"<< endl;
    }
    Matrix operator+ (Matrix a){
        Matrix result;
        for(int i=0; i<4; i++)
            result.arr[i] = this->arr[i] + a.arr[i];
        return result;
    }
    Matrix operator+= (Matrix &b){
        for(int i=0; i<4; i++)
            this->arr[i] += b.arr[i];
        return *this;
    }
    bool operator== (Matrix c){
        for(int i=0; i<4; i++)
            if (this->arr[i] != c.arr[i]){
                return false;
            }
        return true;
    }
};

int main() {
    Matrix a(1,2,3,4), b(2,3,4,5), c;
    c = a + b;
    a += b;
    a.show(); b.show(); c.show();
    if(a==c)
        cout << "a and c are the same" << endl;
    return 0;
}
