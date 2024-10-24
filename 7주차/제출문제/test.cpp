#include <iostream>
using namespace std;
#include <string>
#include <cstring>

int main(){
    int *p = new int[10]{1,2,3};
    cout<<(*p);
    delete []p;
}