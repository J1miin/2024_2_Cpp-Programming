#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int iOperand1, iOperand2;
    int result=0;
    char cOperator[2];
    int track;
    string sInput;
    while (true){
        cout<<"? (연산자에 ?를 입력하면 종료됩니다.)";
        //cin >> iOperand1 >> cOperator >> iOperand2;
        getline(cin,sInput,'\n');
        track = sInput.find(' ',0);
        if (track!=-1){
            result += stoi(sInput.substr(0,track));
            cout<<result<<endl;
        }

        if (strcmp(cOperator,"+")==0){
            cout<<iOperand1<<" " <<cOperator<<" " <<iOperand2<<" = "<<iOperand1+iOperand2<< endl;
        }else if (strcmp(cOperator,"-")==0){
            cout<<iOperand1<<" " <<cOperator<<" " <<iOperand2<<" = "<<iOperand1-iOperand2<< endl;
        }else if (strcmp(cOperator,"*")==0){
            cout<<iOperand1<<" " <<cOperator<<" " <<iOperand2<<" = "<<iOperand1*iOperand2<< endl;
        }else if (strcmp(cOperator,"/")==0){
            cout<<iOperand1<<" " <<cOperator<<" " <<iOperand2<<" = "<<iOperand1/iOperand2<< endl;
        }else if (strcmp(cOperator,"%")==0){
            cout<<iOperand1<<" " <<cOperator<<" " <<iOperand2<<" = "<<iOperand1%iOperand2<< endl;
        }else if (strcmp(cOperator,"?")==0){
            cout<<"종료합니다.";
            break;
        }else {
            cout<<"잘못된 입력입니다."<<endl;
        }
    }
    
    return 0;
}