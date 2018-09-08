#include <string>
#include <iostream>

using namespace std;

class MyArray {
public:
    string *data;
    int length;
    MyArray(string str) {
        length = 0;
        int strLen = str.size();
        data = new string[strLen];
        for(int i = 0; i < strLen - 1; i++) {
            string substr;
            char c1 = str[i];
            char c2 = str[i+1];
            if(!isAlphaandChangeSmall(c1))
                continue;
            if(!isAlphaandChangeSmall(c2))
                continue;

            substr += string(1, c1);
            substr += string(1, c2);

            pushDataList(substr);
        }
    }
    bool isAlphaandChangeSmall(char &c) {
        if(int('A') <= int(c) && int(c) <= int('Z')){
            c = (int)c + 32;
            return true;
        }
        else if(int('a') <= int(c) && int(c) <= int('z')) {
            return true;
        }
        else
            return false;
    }

    void pushDataList(string str) {
        data[length] = str;
        length++;
    }
    ~MyArray() {
        delete[] data;
    }
};

int solution(string str1, string str2) {
    int answer = 0;
    double jarcard = 1;      // 자카드 유사도
    int kyoNum = 0;
    int hapNum = 0;


    MyArray str1Arr(str1);
    MyArray str2Arr(str2);

    for (int i = 0; i < str1Arr.length; i++) {         //교집합의 원소들을 배열 result에 순차적으로 저장하기 위한 for문
        for (int j = 0; j < str2Arr.length; j++) {
            if (str1Arr.data[i] == str2Arr.data[j] && !(str2Arr.data[j] == "")) {
                kyoNum++;
                str2Arr.data[j] = "";
                break;
            }
        }
    }

    hapNum = str1Arr.length + str2Arr.length - kyoNum;

    jarcard = ((double)kyoNum / (double)hapNum);
    if(str1Arr.length == 0 && str2Arr.length == 0)
        jarcard = 1;

    answer = (double)(jarcard * (double)65536);
    return answer;
}


int main() {
    cout << (solution("aa1+aa2","AAAA12"));
}
