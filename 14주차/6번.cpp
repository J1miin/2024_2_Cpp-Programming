#include<iostream>
using namespace std;

int* concat(int a[], int sizea, int b[], int sizeb);

int main(){
    int x[]={1,2,3,4,5};
    int y[]={10,20,30,40,50};
    try{
        int *p = concat(x,5,y,4);
        for(int n=0;n<9;n++){
            cout<<p[n]<<' ';
        }
        cout<<endl;
        delete []p;
    }   
    catch(int failCode){
        cout<<"오류코드: "<<failCode <<endl;
    }
}

int* concat(int a[], int sizea, int b[], int sizeb){
    if (sizea <= 0 || sizeb <= 0 || a==NULL || b==NULL){
        throw -1;
    }
    int size = sizea + sizeb;
    int * newArr= new int[size];
    for(int i=0;i<sizea;++i){
        newArr[i]=a[i];
    }
    for(int i=0;i<sizeb;++i){
        cout<<b[i]<<endl;
        newArr[i+sizea]=b[i];
    }
    return newArr;

}