#include <iostream>
#include <string>
using namespace std;

class Morse{
    string alphabet[26];
    string digit[10];
    string slash, question, comma, period, plus, equal;
public:
    Morse();
    void text2Morse(string text, string& morse);
    bool morse2Text(string morse, string& text);
};

Morse::Morse(){ 
    //생성자 초기화
    alphabet[0] = ".-"; alphabet[1] = "-..."; alphabet[2] = "-.-."; alphabet[3] = "-..";
    alphabet[4] = "."; alphabet[5] = "..-."; alphabet[6] = "--."; alphabet[7] = "....";
    alphabet[8] = ".."; alphabet[9] = ".---"; alphabet[10] = "-.-"; alphabet[11] = ".-..";
    alphabet[12] = "--"; alphabet[13] = "-."; alphabet[14] = "---"; alphabet[15] = ".--.";
    alphabet[16] = "--.-"; alphabet[17] = ".-."; alphabet[18] = "..."; alphabet[19] = "-";
    alphabet[20] = "..-"; alphabet[21] = "...-"; alphabet[22] = ".--"; alphabet[23] = "-..-";
    alphabet[24] = "-.--"; alphabet[25] = "--.."; digit[0] = "-----"; digit[1] = ".----";
    digit[2] = "..---"; digit[3] = "...--"; digit[4] = "....-"; digit[5] = ".....";
    digit[6] = "-...."; digit[7] = "--..."; digit[8] = "---.."; digit[9] = "----.";
    slash = "-..-."; question = "..--.."; comma = "--..--"; period = ".-.-.-";
    plus = ".-.-"; equal = "-...-";
}

void Morse::text2Morse(string text, string& morse){
    int iLen = text.length();
    for (int i=0;i<iLen;++i){
        int check = int(text[i]); //아스키코드로 바꾼 것
        if(isalpha(text[i])){
            check-=97;
            morse += alphabet[check]+" ";
        }else if(check==47){
            // '/'일 때
            morse += slash+" ";
        }else if(check==63){
            morse += question+" ";
        }else if (check==44){
            morse += comma+" ";
        }else if (check==46){
            morse += period+" ";
        }else if(check==43){
            morse+=plus+" ";
        }else if(check==61){
            morse+=equal+" ";
        }else if(check>=48 && check<=57){
            //숫자일 경우
            check -= 48;
            morse += digit[check]+" ";
        }else if(text[i] ==' '){ //문자라서 ' '로 비교해야한다. ""는 문자열이다.
            //공백일 때,
            if ((i+1 <iLen) && text[i+1]== ' '){
                morse += "   ";
            }else{
                morse += " ";
            }
        }
    }
}
bool Morse::morse2Text(string morse, string& text){
    string alpha[26] = { "a","b","c","d","e","f", "g","h","i", "j","k","l", "m","n","o",
    "p","q","r", "tmp","t","u", "v","w","x", "y","z" };
    string di[10] = { "0","1","2", "3","4","5", "6","7","8", "9" };
    
    int iMorseLen = morse.length();
    string tmp="";
    string result ="";

    for (int iStart=0;iStart<iMorseLen;++iStart){
        if (morse[iStart] != ' ') { 
            tmp += morse[iStart]; // 모스 부호를 하나씩 더해감
        } else {
            // 공백을 만나면 일단 완성된 모스 부호를 처리
            bool check = true;
            int i;

            // 알파벳인지 확인
            for (i = 0; i < 26; ++i) {
                if (tmp == alphabet[i]) { //흠.. 다 찾아야 하는건가... ㅠㅠ
                    result.append(alpha[i]);
                    check = false; //알파벳이었다는 뜻 
                    break;
                }
            }
            //digit OR 특수기호 OR 띄어쓰기
            //digit인 경우
            if (check == true){
                for (int i=0; i<10;++i){
                    if (tmp == digit[i]){
                        result.append(di[i]);
                        check = false; //숫자였다는 뜻
                        break;
                    }
                }
            }
            //특수기호인 경우
            if(check == true){
                check = false;
                if (tmp == slash) result += "/";
                else if (tmp == question) result += "?";
                else if (tmp == comma) result += ",";
                else if (tmp == period) result += ".";
                else if (tmp == plus) result += "+";
                else if (tmp == equal) result += "=";
                else check = true; //특수기호가 아니었다는 뜻
            }
            if (check==true){
                result += " ";
            }
            tmp="";
        }
    }
    cout<<result<<endl;
    if (result==text){
        return true;
    }else {
        return false;
    }
}
int main(){
    string morseResult = "";
    string text = "lets meet 4 pm 2014.";
    Morse morse;
    morse.text2Morse(text, morseResult);
    cout<< morseResult;
    
    
    if (morse.morse2Text(morseResult,text)==true){
        cout<<"success"<<endl;
    }else{
        cout<<endl<<"fail"<<endl;
    };
    return 0;
}