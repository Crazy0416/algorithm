#include <iostream>
#include <memory.h>

using namespace std;

int N, M;
int cheeseCnt = 0;
int resultHours = 0;
int map[101][101];
bool visit[101][101] = {false,};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void setData() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) cheeseCnt++;
        }
    }
}

void resetVisit() {
    memset(visit, false, sizeof(visit));
}

void checkAirDFS(int x, int y) {
    visit[y][x] = true;
    map[y][x] = -1;

    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N) continue;

        if(map[next_y][next_x] != 1 && !visit[next_y][next_x])
            checkAirDFS(next_x, next_y);
    }
}

void checkMeltCheese(int x, int y) {
    int cnt = 0;

    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(map[next_y][next_x] == -1 && !visit[next_y][next_x]) {
            cnt++;
        }

        if(cnt >= 2) {
            visit[y][x] = true;
            map[y][x] = 0;
            cheeseCnt--;
            break;
        }
    }
}

void solution() {
    while(cheeseCnt > 0) {
        checkAirDFS(0,0);
        resetVisit();

        for(int y = 0; y < N; y++) {
            for(int x = 0; x < M; x++) {
                if(map[y][x] == 1 && !visit[y][x]) {
                    checkMeltCheese(x, y);
                }
            }
        }
        resetVisit();
        resultHours++;
    }
}

int main() {
    setData();
    solution();

    cout << resultHours << endl;

    return 0;
}