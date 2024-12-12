#include <iostream>
using namespace std;

class Dept{
    int size; //scores 배열의크기
    int * scores; //동적 할당 받을 정수 배열의 주소 
public:
    Dept(int size){
        this->size = size;
        scores = new int[size];
    }
    Dept(const Dept& dept){
        this->size=dept.size;
        this->scores = new int[this->size];
        for (int i=0 ; i< this->size ; ++i){
            this->scores[i] = dept.scores[i];
        }
    }; //복사생성자
    ~Dept(){
        delete []scores;
    };
    int getSize(){
        return size;
    }
    void read(){ //size만큼 키보드에서 정수를 읽어 scores배열에 저장
        cout << size << "개 정수 입력 >> ";
        for (int i=0;i<size ; ++i){
            cin>>scores[i];
        }
    } 
    bool isOver60(int index){//index의 학생의 성적이 60 이상이면 true 리턴
        if (scores[index]>60 || scores[index]==60){
            return true;
        }else {return false;}
    }
};

int countPass(Dept dept){ //객체를 값으로 전달하기 때문에 복사생성자가 호출된다.
    int count = 0;
    for (int i=0; i<dept.getSize(); ++i){
        if (dept.isOver60(i)){
            count++;
        }
    }
    return count;
}

int main(){
    Dept com(10); //10명이 있는 학과 com
    com.read(); //10명의 학생들의 성적을 키보드로 읽어서 scores 배열에 저장
    int n = countPass(com); //com학과에 60점 이상으로 통과한 학생의 수 리턴
    cout << "60점 이상은" << n << "명";
}