#include <string>
#include <iostream>

using namespace std;

class Set {
public:
    int setScore;
    int score;
    string area;
    string option;
    Set() {
        this->setScore = 0;
        this->score = 0;
        this->area = "\0";
        this->option = "\0";
    }
    void setSetString(string &dartResult) {
        string dumpScore;
        int idx;
        for(idx = 0; (dartResult[idx] != 'S') && (dartResult[idx] != 'D') && (dartResult[idx] != 'T'); idx++)
            dumpScore += dartResult[idx];

        this->score = atoi(dumpScore.c_str());
        this->area = dartResult[idx];
        idx++;

        if(dartResult[idx] == '*' || dartResult[idx] == '#') {
            this->option = dartResult[idx]; idx++;
        }

        dartResult = dartResult.substr(idx);
    }
    void decideSetScore(Set* prevSet) {
        if(this->area == "S")
            this->setScore = this->score * 1;
        else if(this->area == "D")
            this->setScore = this->score * this->score;
        else if(this->area == "T")
            this->setScore = this->score * this->score * this->score;

        if(this->option == "*")
            this->setScore *= 2;
        else if(this->option == "#")
            this->setScore *= -1;

        if(prevSet != NULL){
            if(this->option == "*")
                prevSet->setScore *= 2;
        }
    }
};


int solution(string dartResult) {
    int answer = 0;
    Set set[3];
    int setSize = 0;

    for(; dartResult != "\0"; setSize++)
        set[setSize].setSetString(dartResult);

    for(int i = 0; i < setSize; i++ ){
        if(i == 0){
            set[i].decideSetScore(NULL);
            continue;
        }
        set[i].decideSetScore(&set[i-1]);
    }

    for(int i = 0; i < setSize; i++ ){
        answer += set[i].setScore;
    }

    return answer;
}

int main() {
    cout << solution("1D2S#10S");
    return 0;
}