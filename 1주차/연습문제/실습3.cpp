#include <iostream>

int main() {
    int sum = 0;
    for (int i=0;i<10;++i){
        sum += i+1;
    }
    std::cout << "1에서 10까지 더한 결과는 " << sum << "입니다";
    return 0;
}