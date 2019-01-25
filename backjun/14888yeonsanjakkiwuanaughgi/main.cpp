#include <iostream>
#include <math.h>
#define INF 987654321


using namespace std;

void solution(int sequence[], int operatorCnt[], long long prev, int idx, long long &MAX, long long &MIN) {
    int operRemainCnt = 0;

    for(int i = 0; i < 4; i++) {
        operRemainCnt += operatorCnt[i];
        if(operatorCnt[i] != 0 && i == 0) {
            operatorCnt[i]--;
            long long result = prev + (long long)sequence[idx+1];
            solution(sequence, operatorCnt, result, idx + 1, MAX, MIN);
            operatorCnt[i]++;
        } else if(operatorCnt[i] != 0 && i == 1) {
            operatorCnt[i]--;
            long long result = prev - (long long)sequence[idx+1];
            solution(sequence, operatorCnt, result, idx + 1, MAX, MIN);
            operatorCnt[i]++;
        } else if(operatorCnt[i] != 0 && i == 2) {
            operatorCnt[i]--;
            long long result = prev * (long long)sequence[idx+1];
            solution(sequence, operatorCnt, result, idx + 1, MAX, MIN);
            operatorCnt[i]++;
        } else if(operatorCnt[i] != 0 && i == 3) {
            operatorCnt[i]--;
            long long dump = abs(prev);
            long long result = dump / (long long)sequence[idx+1];

            if(prev < 0) {
                result *= -1;
            }
            solution(sequence, operatorCnt, result, idx + 1, MAX, MIN);
            operatorCnt[i]++;
        }
    }

    // 재귀 종결 조건
    if(operRemainCnt == 0){
        if(MAX < prev)
            MAX = prev;
        if(MIN > prev)
            MIN = prev;
        return;
    }
}

int main() {
    int N;
    int *sequence = new int[N];
    int operatorCnt[4];
    long long MAX = -INF, MIN = INF;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> sequence[i];
    for(int i = 0; i < 4; i++)
        cin >> operatorCnt[i];

    solution(sequence, operatorCnt, sequence[0], 0, MAX, MIN);
    cout << MAX << endl << MIN;
    return 0;
}