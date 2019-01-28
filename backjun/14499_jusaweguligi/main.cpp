#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

deque<int> dirCmd;
vector<vector<int>> map(20, vector<int>(20, 0));
vector<vector<int>> dice(4, vector<int>(3, 0));
pair<int, int> curPos;

void changeDiceBottom() {
    if(map[curPos.first][curPos.second] == 0)
        map[curPos.first][curPos.second] = dice[3][1];
    else {
        dice[3][1] = map[curPos.first][curPos.second];
        map[curPos.first][curPos.second] = 0;
    }
}

// 서
bool moveLeft(int M, int N) {
    if(curPos.second < 0) {
        curPos.second++;
        return false;
    }

    queue<int> dump;
    dump.push(dice[3][1]);
    dump.push(dice[1][2]);
    dice[3][1] = dice[1][0];
    dice[1][2] = dump.front(); dump.push(dice[1][1]); dump.pop();
    dice[1][1] = dump.front(); dump.push(dice[1][0]); dump.pop();
    dice[1][0] = dump.front();

    return true;
}

// 동
bool moveRight(int M, int N) {
    if(curPos.second >= M) {
        curPos.second--;
        return false;
    }

    queue<int> dump;
    dump.push(dice[1][2]);
    dump.push(dice[3][1]);
    dice[1][2] = dice[1][1];
    dice[3][1] = dump.front(); dump.push(dice[1][0]); dump.pop();
    dice[1][0] = dump.front(); dump.push(dice[1][1]); dump.pop();
    dice[1][1] = dump.front();

    return true;
}

// 북
bool moveUp(int M, int N) {
    if(curPos.first < 0) {
        curPos.first++;
        return false;
    }

    queue<int> dump;
    dump.push(dice[3][1]);
    dump.push(dice[2][1]);
    dice[3][1] = dice[0][1];
    dice[2][1] = dump.front(); dump.push(dice[1][1]); dump.pop();
    dice[1][1] = dump.front(); dump.push(dice[0][1]); dump.pop();
    dice[0][1] = dump.front();

    return true;
}

// 남
bool moveDown(int M, int N) {
    if(curPos.first >= N ) {
        curPos.first--;
        return false;
    }

    queue<int> dump;
    dump.push(dice[2][1]);
    dump.push(dice[3][1]);
    dice[2][1] = dice[1][1];
    dice[3][1] = dump.front(); dump.push(dice[0][1]); dump.pop();
    dice[0][1] = dump.front(); dump.push(dice[1][1]); dump.pop();
    dice[1][1] = dump.front();

    return true;
}

int main() {
    int N, M, X, Y, K;

    cin >> N >> M >> X >> Y >> K;
    curPos = make_pair(X, Y);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            cin >> map[i][j];
    }

    for(int i = 0; i < K; i++) {
        int dump; cin >> dump;
        dirCmd.push_back(dump);
    }


    while(K--) {
        int dir = dirCmd.front(); dirCmd.pop_front();

        switch (dir) {
            case 1:
                curPos.second++;
                if(moveRight(M, N)) {
                    changeDiceBottom();
                    cout << dice[1][1] << endl;
                }
                break;
            case 2:
                curPos.second--;
                if(moveLeft(M, N)) {
                    changeDiceBottom();
                    cout << dice[1][1] << endl;
                }
                break;
            case 3:
                curPos.first--;
                if(moveUp(M, N)) {
                    changeDiceBottom();
                    cout << dice[1][1] << endl;
                }
                break;
            case 4:
                curPos.first++;
                if(moveDown(M, N)) {
                    changeDiceBottom();
                    cout << dice[1][1] << endl;
                }
                break;
        }
        //showDice();
    }


    return 0;
}