#include <iostream>

int main(){
    char name[20];
    std::cout << "write your name: ";
    std::cin >> name ;
    std::cout << name <<" welcome";
    return 0;
}
//12-(1) 기태님 환영합니다.
//12-(2) 기태님 환영합니다. -> 공백을 포함할 수 없어서 기태까지만 버퍼에 들어감.