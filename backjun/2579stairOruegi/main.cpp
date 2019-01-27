#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int stairCnt;
vector<vector<long>> dp(302, vector<long>(2, 0));
vector<int> stairPoint;

int main() {
    stairPoint.reserve(302);

    cin >> stairCnt;

    for(int i = 1; i <= stairCnt; i++) {
        int dump; cin >> dump;
        stairPoint.push_back(dump);

        if(i == 1) {
            dp[1][0] = dump;
            dp[1][1] = dump; continue;
        }
        if(i == 2) {
            dp[2][0] = dump;
            dp[2][1] = dp[1][1] + dump; continue;
        }

        dp[i][0] = max(dp[i-2][1], dp[i-2][0]) + dump;  //
        dp[i][1] = dp[i-1][0] + dump;                   // 이전 계단에서 한 계단 올라온 경우
    }

    cout << max(dp[stairCnt][0], dp[stairCnt][1]);


    return 0;
}