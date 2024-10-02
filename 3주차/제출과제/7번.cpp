#include <iostream>
#include <cstdlib>
#include <ctime>
#define RAND_MAX 32767
using namespace std;

class Random {
public:
    Random();
    int next();
    int nextInRange(int start, int end);
};

Random::Random(){
    srand((unsigned)time(0));
}
int Random::next(){
    int n;
    while (true){
        n= rand()%(RAND_MAX+1);
        if(n%2==0){
            return n;
        }
    }
}

int Random:: nextInRange(int start, int end){
    int range;
    int oddNum ;
    while (true){
        range =(end-start)+1;
        oddNum=start+(rand()%range);
        if (oddNum %2 != 0){
            return oddNum;
        }
    }
}

int main(){
    Random r;
    cout<< "-- 0에서 "<< RAND_MAX <<"까지의 랜덤 정수 10개 --"<<endl;
    for (int i=0; i<10; i++){
        int n = r.next();
        cout<< n<< ' ';
    }
    cout << endl << endl << "-- 2에서 "<< "10까지의 랜덤 정수 10개 --" << endl;
    for (int i=0; i<10; ++i){
        int n=r.nextInRange(2,10);
        cout<< n << ' ';
    }
    cout << endl;
}