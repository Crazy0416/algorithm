#include <iostream>
#include <queue>

using namespace std;

int N, K;
int myResult = 100000;
bool check[100001] = {false,};

void bfs() {
    queue<pair<int, int>> que;
    que.push(make_pair(N, 0));
    check[N] = true;

    while(!que.empty()) {
        pair<int, int> data = que.front();
        que.pop();

        int cur_N = data.first;
        int t = data.second;

        if(cur_N < 0 || cur_N > 100000) continue;

        if(cur_N == K) {
            myResult = t;
            return;
        }

        if(cur_N + 1 <= 100000 && !check[cur_N + 1]) {
            check[cur_N + 1] = true;
            que.push(make_pair(cur_N + 1, t + 1));
        }
        if(cur_N - 1 >= 0 && !check[cur_N - 1]) {
            check[cur_N - 1] = true;
            que.push(make_pair(cur_N - 1, t + 1));
        }
        if(cur_N * 2 <= 100000 && !check[cur_N * 2]) {
            check[cur_N * 2] = true;
            que.push(make_pair(cur_N * 2, t + 1));
        }
    }
}


int main() {

    cin >> N >> K;

    bfs();

    cout << myResult;

    return 0;
}