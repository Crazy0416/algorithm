#include <iostream>
#include <cstring>
#define MAX_SIZE 9999999;

using namespace std;

int getTeamSub(int N, int **S, bool *teamArr) {
    int trueResult = 0;
    int falseResult = 0;

    for(int i = 0; i < N; i++) {
        if(teamArr[i] == true){
            for(int j = 0; j < N ; j++) {
                if(teamArr[j] == true && j != i)
                    trueResult += S[i][j];
            }
        } else {
            for(int j = 0; j < N; j++) {
                if(teamArr[j] == false && j != i)
                    falseResult += S[i][j];
            }
        }
    }

    return abs(trueResult - falseResult);
}

void checkAllMethodsDFS(int N, int **S, int trueTeamCnt, int prevIdx, bool *teamArr, int &minResult) {
    // 종료 조건
    if((N / 2) == trueTeamCnt) {
        int result = getTeamSub(N, S, teamArr);
        if(result < minResult)
            minResult = result;

        return;
    }


    for(int i = prevIdx; i < N; i++) {
        if(teamArr[i] == false) {
            teamArr[i] = true;
            checkAllMethodsDFS(N, S, trueTeamCnt + 1, i, teamArr, minResult);
            teamArr[i] = false;
        }
    }
}

int solution(int N, int **S) {
    bool *teamArr = new bool[N];
    memset(teamArr, false, N);
    int minResult = MAX_SIZE;

    checkAllMethodsDFS(N, S, 0, 0, teamArr, minResult);

    return minResult;
}

int main() {
    int N;
    cin >> N;
    int **S = new int*[N];
    for(int i = 0; i < N; i++)
        S[i] = new int[N];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> S[i][j];

    cout << solution(N, S);

    return 0;
}