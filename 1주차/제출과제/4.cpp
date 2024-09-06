#include <iostream>

int main(){
    for (int i=0; i<4; ++i){
        for (int j=0;j<i+1;++j){
            std::cout<<"*";
        }
        std::cout<<"\n";
    }
    return 0;
}