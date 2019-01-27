#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void allocMap(int **&map, int N) {
    map = new int*[N];

    for(int i = 0; i < N; i++) {
        map[i] = new int[N];
        fill_n(map[i], N, 0);
    }
}

void initMap(int **&map, int N) {
    char dump;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> dump;
            map[i][j] = (dump == '0') ? 0 : 1;
        }
    }
}

void showMap(int **&map, int N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void eraseApart(int **&map, int N, int i, int j, vector<int>& apartInfo) {
    queue<pair<int, int>> bfs;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    bfs.push(pair<int, int>(i, j));
    int danziCnt = 0;

    do{
        pair<int, int> data = bfs.front();
        bfs.pop();
        if(map[data.first][data.second] == 0)
            continue;

        map[data.first][data.second] = 0;
        danziCnt++;


        for(int k = 0; k < 4; k++) {
            int x = data.first + dx[k];
            int y = data.second + dy[k];

            if(x >= N || x < 0)
                continue;
            if(y >= N || y < 0)
                continue;

            if(map[x][y] == 1) {
                bfs.push(pair<int, int>(x, y));
            }
        }
    } while(bfs.size() != 0);

    apartInfo.push_back(danziCnt);
}

int solution(int **&map, int N, vector<int>& apartInfo) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 1) {
                eraseApart(map, N, i, j, apartInfo);
            }
        }
    }
}

int main() {
    int N;
    int **map = NULL;
    vector<int> apartInfo;


    cin >> N;

    allocMap(map, N);
    initMap(map, N);

    solution(map, N, apartInfo);

    cout << apartInfo.size() << endl;
    sort(apartInfo.begin(), apartInfo.end());

    for(int i = 0; i < apartInfo.size(); i++) {
        cout << apartInfo[i] << endl;
    }

    return 0;
}