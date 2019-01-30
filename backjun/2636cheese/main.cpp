#include <iostream>
#include <memory.h>

using namespace std;

int Y, X;
int map[101][101];
bool visit[101][101] = {false,};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int sideCnt = 0;
int cheeseCnt = 0;
int resultTime = 0;

void setData() {
    cin >> Y >> X;
    for(int i = 0; i < Y; i++) {
        for(int j = 0; j < X; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) cheeseCnt++;
        }
    }
}

void outSideCheck(int x, int y) {
    map[y][x] = -1;
    visit[y][x] = true;

    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || next_y < 0 || next_x >= X || next_y >= Y)
            continue;

        if(map[next_y][next_x] != 1 && !visit[next_y][next_x])
           outSideCheck(next_x, next_y);
    }
}

void checkMelt(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if(map[next_y][next_x] == -1 && !visit[next_y][next_x]) {
            sideCnt++;
            cheeseCnt--;
            visit[y][x] = true;
            map[y][x] = 0;
            break;
        }
    }
}

void visitReset() {
    memset(visit, false, sizeof(visit));
}


void simulation() {

    while (cheeseCnt > 0) {
        sideCnt = 0;
        outSideCheck(0, 0);
        visitReset();

        for(int i = 0; i < Y; i++) {
            for(int j = 0; j < X; j++) {
                if(map[i][j] == 1 && !visit[i][j])
                    checkMelt(j, i);
            }
        }
        visitReset();

        resultTime++;
    }
}
int main() {
    setData();
    simulation();

    cout << resultTime << endl
        << sideCnt << endl;

    return 0;
}