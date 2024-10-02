#include <iostream>
using namespace std;

class Account{
    string cName;
    int id, iPrice;
public:
    Account(string cName, int id, int iPrice); //기본생성자
    string getOwner();
    int inquiry();
    int withdraw(int iOut); //출금하는 함수
    void deposit(int iIn); //저축하는 함수
};

Account::Account(string cName, int id, int iPrice){
    this->iPrice = iPrice;
    this->cName = cName;
    this->id = id;
}

void Account::deposit(int iIN){
    iPrice+=iIN;
}

int Account::withdraw(int iOut){
    iPrice-=iOut;
    return iOut;
}

int Account::inquiry(){
    return iPrice;
}

string Account::getOwner(){
    return cName;
}

int main(){
    Account a("kitae",1,5000);
    a.deposit(50000);
    cout<<a.getOwner()<<"의 잔액은 "<<a.inquiry()<<endl;
    int money = a.withdraw(20000);
    cout<< a.getOwner()<<"의 잔액은"<< a.inquiry()<<endl;
}