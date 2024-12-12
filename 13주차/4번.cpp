#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin();
    ofstream fout();
    if (!fin || !fout){
        cout<<"fail"<<endl;
        return 0;
    }
    int ch;
    while((ch=fin.get())!=EOF) fout<< (char)toupper(ch);
    fin.close();
    fout.close();
}