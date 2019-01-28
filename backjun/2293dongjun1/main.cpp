#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> coins;
int dp[10001] = {0,};

int main() {
    cin >> N >> K;

    for(int i = 0, dump; i < N; i++) {
        cin >> dump; coins.push_back(dump);
    }

    dp[0] = 1;

    for(int i = 0; i < coins.size(); i++) {
        for(int k = 1; k <= K; k++) {
            if(k >= coins[i]) {
                dp[k] += dp[k - coins[i]];
            }
        }
    }

    cout << dp[K];

    return 0;
}