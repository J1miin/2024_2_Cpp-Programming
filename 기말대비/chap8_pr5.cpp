/*
5. BaseArray를 상속받아 큐처럼 작동하는 MyQueue 클래스를 작성하라. 
MyQueue를 활용하는 사례는 다음과 같다.
<expected result>
큐에 삽입할 5개의 정수를 입력하라>> 1 3 5 7 9
큐의 용량:100, 큐의 크기:5
큐의 원소를 순서대로 제거하여 출력한다>> 1 3 5 7 9
큐의 현재 크기 : 0
*/

#include<iostream>
using namespace std;

class BaseArray{
private:
    int capacity;
    int *mem;
protected :
    BaseArray(int capacity = 100){
        this->capacity=capacity;
        mem= new int[capacity];
    }
    ~BaseArray(){ //소멸자 생성을 까먹지 말자! 
        delete [] mem;
    }
    void put(int index, int val){
        mem[index]=val;
    }
    int get(int index){return mem[index];}
    int getCapacity(){
        return capacity;
    }
};

class MyQueue : public BaseArray{
    MyQueue(int intialSize) : BaseArray(intialSize){
    }
public : 
    int size(){
        return 
    }
    void enqueue(int n){
        put()
    }
};

int main(){
    MyQueue mQ(100);
    int n;
    cout << "type 5 integers to insert into Queue"<<endl;
    for (int i=0;i<5;++i){
        cin >> n;
        mQ.enqueue(n);
    }
    cout <<"capacity of Queue : "<<mQ.capacity()<<", size of Queue"<<mQ.size()<<endl;
    cout <<"pop elements of Queue>>";
    while (mQ.size()!=0){
        cout << mQ.dequeue() << " "; 
    }
    cout<<endl<<"size of Queue after dequeue"<<endl;
}