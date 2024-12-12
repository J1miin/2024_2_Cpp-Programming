#include <iostream>
using namespace std;
 
istream& pos (istream& ins) { 
    //스트림에서 문자 한 개 가져온 뒤, ins에 저장함.(이 때 int로 형변환 된다.)
    cout << "위치는? ";
    return ins;
}
 
int main() {
    int x, y;
    cin >> pos >> x;
    cin >> pos >> y;
    cout << x << ',' << y << endl;
}