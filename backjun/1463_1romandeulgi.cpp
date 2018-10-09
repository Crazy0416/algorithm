#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999999

using namespace std;

vector<int> dp(1000001,0);

int main() {
    int N;
    cin >> N;

    for(int i = 2; i <= N; i++) {
       int dump1 = (i % 3 == 0) ? dp[i / 3] + 1 : INF;
       int dump2 = (i % 2 == 0) ? dp[i / 2] + 1 : INF;
       int dump3 = dp[i-1] + 1;

       dp[i] = min(min(dump1, dump2), dump3);
    }

    cout << dp[N];

    return 0;
}