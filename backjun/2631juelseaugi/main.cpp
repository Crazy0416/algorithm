#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> lines;
int dp[201] = {0,};

void setData() {
    cin >> N;
    lines.push_back(0);
    for(int i = 0, dump; i < N; i++) {
        cin >> dump;
        lines.push_back(dump);
    }
}

void solution() {
    for(int i = 1; i <= lines.size(); i++) {
        int dst = lines[i];
        int maxDp = 0;

        for(int di = 1; di <= i; di++) {
            if(dst > lines[di])
                if(maxDp < dp[di])
                    maxDp = dp[di];
        }
        dp[i] = maxDp + 1;
    }
    int maxDp = 0;
    for(int i = 1; i <= lines.size(); i++)
        if(maxDp < dp[i])
            maxDp = dp[i];

    cout << N - maxDp << endl;
}

int main() {
    setData();
    solution();

    return 0;
}