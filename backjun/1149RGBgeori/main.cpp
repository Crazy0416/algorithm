#include <iostream>

using namespace std;

int N;
int costs[1001][3];
int dp[1001][3] = {0,};

void set_cost() {
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 3; j++)
            cin >> costs[i][j];
    }
}

void solution() {
    for(int i = 1; i <= N; i++) {
        dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);  // 0은 R
        dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);  // 1은 G
        dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);  // 2은 B
    }

    cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << endl;
}

int main() {
    cin >> N;
    set_cost();

    solution();

    return 0;
}