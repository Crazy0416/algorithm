#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> T;
vector<int> P;
vector<int> dp(16, 0);

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int t, p;
        cin >> t >> p;
        T.push_back(t);
        P.push_back(p);
    }

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            if(i - j >= T[j])
                dp[i] = max(dp[i], P[j] + dp[j]);
        }
    }


    cout << dp[N];

    return 0;
}