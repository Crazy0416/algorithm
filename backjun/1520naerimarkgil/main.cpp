#include <iostream>

using namespace std;

int N, M;
int **map;
int **dp;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void setData() {
    cin >> M >> N;

    map = new int*[M];
    dp = new int*[M];
    for(int i = 0; i < M; i++) {
        map[i] = new int[N]{0,};
        dp[i] = new int[N]{0,};
    }

    for(int i = 0; i < M; i++) {
        for(int  j = 0; j < N; j++)
            cin >> map[i][j];
    }
}

void showDP() {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int dfs(int x, int y) {
    if(x == N - 1 && y == M - 1)
        return 1;
    if(dp[y][x] > 0)
        return dp[y][x];

    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
            continue;

        if(map[next_y][next_x] < map[y][x])
            dp[y][x] += dfs(next_x, next_y);    /// 현재 경로에서 갈 수 있는 경로의 dp를 전부 더해준다.
    }
    showDP();
    return dp[y][x];    /// x, y 이전의 dp에게 값을 전달하기 위함.
}

void solution() {
    dfs(0, 0);
    cout << dp[0][0] << endl;
}

int main() {
    setData();
    solution();

    return 0;
}