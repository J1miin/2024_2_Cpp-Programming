#include <iostream>
using namespace std;
//4. 아래와 같이 원형이 주어진 bigger()를 작성하고 
//사용자로부터 2개의 정수를 입력받아 큰 값을 출력하는 main()을 작성하라. 
//bigger()는 인자로 주어진 a, b가 같으면 true. 
//아니면 false를 리턴하고 큰 수는 big에 전달한다.

bool bigger(int a, int b, int& big){
    if (a>b){
        big = a;
        return false;
    }else if (a<b){
        big = b;
        return false;
    }else {
        big = a;
        return true;
    }
}

int main() {
    int iA, iB, big;
    big = 0;
    cout<<"두 개의 정수를 입력하세요";
    cin >> iA >> iB;
    bool result = bigger(iA, iB, big);
    cout <<"큰 수 : "<< big << " bool 값 :"<< result;
    return 0;
}