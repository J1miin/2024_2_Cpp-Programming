#include <iostream>

//(1)
int main(){
    int count =0;
    std:: cin >> count;
    std:: cout << count +1 ; // std 사용하지 않은 문제
    return 0;
}
//(2)
/*
using namespace std; <<요게 더 좋다.
int main(){
    //std 선언을 하지 않음.
    std::cout <<"i love c++" << std::endl; //endl을 안쓴 것이 문제가 됨
    std::cout <<"i love programming";
    return 0;
}
*/

