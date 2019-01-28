#include <iostream>
#include <cmath>

using namespace std;

int N;
int wines[10001] = {0,};
int dp[10001][2] = {0,};        // dp[i][k]: i잔까지 마신 와인 양의 최댓값. k=0은 i-3 -> i-1잔에서 한칸 넘어온 경우

void setData() {
    cin >> N;

    for(int i = 1; i <= N; i++)
        cin >> wines[i];
}

void solution() {
    dp[1][0] = wines[1];    // i-1 잔에서 1칸 넘어 i 잔으로 온 경우
    dp[1][1] = wines[1];
    dp[2][0] = wines[1] + wines[2];
    dp[2][1] = wines[2];

    for(int i = 3; i <= N; i++) {
        dp[i][0] = dp[i-1][1] + wines[i];
        dp[i][1] = max(dp[i-1][0], max(dp[i-2][0] + wines[i], dp[i-2][1] + wines[i]));  //  i-2에서 i-1로 오고 i칸을 안마시는 경우도 있음.

    }
}

int main() {
    setData();
    solution();

    cout << max(dp[N][0], dp[N][1]) << endl;

    return 0;
}