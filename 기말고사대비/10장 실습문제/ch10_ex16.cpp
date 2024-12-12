//practice lambda equation using auto operator
#include <iostream>
#include <string>
using namespace std;

int main(){
    auto love = [](string a, string b){
        cout<<a<<"보다 "<<b<<"가 좋아"<<endl;
    };
    love("비냉","물냉");
    auto cal = [](int x, int y)-> int {return x+y;};
    cout<<cal(1,2)<<endl;
    
}