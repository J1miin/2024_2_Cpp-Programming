#include <iostream>
#include <string>
using namespace std;


class Person{
    string name;
    string tel;
public:
    Person(){};
    string getName(){
        return name;
    }
    string getTel(){
        return tel;
    }
    void set(string name, string tel){
        this->name = name;
        this->tel = tel;
    };
};

int main(){
    Person personArr[3]; //크기가 3인 객체 배열
    string str, name, tel, searchName;
    int j =0;
    cout<<"이름과 전화 번호를 입력해 주세요"<<endl;
    for (int i=0;i<3;++i){
        cout<<"사람"<< (i+1)<<">>";
        getline(cin,str,'\n');
        name = str.substr(0,str.find(" "));
        tel = str.substr(str.find(" ")+1,str.length());
        personArr[i].set(name, tel);
    }
    cout<<"모든 사람의 이름은 ";
    for (int i=0;i<3;++i){
        cout<<personArr[i].getName()<<" ";
    }
    cout<<endl<<"전화번호 검색합니다. 이름을 입력하세요>>";
    cin>>searchName;

    for (int i=0; i<3 ; ++i){
        name = personArr[i].getName();
        if(name.compare(searchName)==0){
            cout<<"전화 번호는 "<<personArr[i].getTel()<<endl;
        }
    }
    return 0;
}