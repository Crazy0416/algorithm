#include <iostream>
#include <list>
using namespace std;

struct XY {
    int x;
    int y;
};

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


void initMap(int n, int m, int **(&map)) {
    map = new int*[n];

    for(int i = 0; i < n; i++) {
        map[i] = new int[m];
    }
}

void setMap(int n, int m, int **(&map)) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
}

void deepCopyMap(int n, int m, int **map, int **(&cloneMap)){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cloneMap[i][j] = map[i][j];
}

void deleteHeap2DMap(int n, int **map) {
    for(int i = 0; i < n; i++)
        delete[] map[i];
}

int simulateVirusGetSize(int n, int m, int **(&cloneMap)) {
    int shelterSize = 0;
    int **simulateMap;
    list<struct XY> bfsQueue;
    initMap(n, m, simulateMap);
    deepCopyMap(n, m, cloneMap, simulateMap);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(simulateMap[i][j] == 2){
                struct XY point = {i, j};
                bfsQueue.push_back(point);
            }
        }
    }

    while(!bfsQueue.empty()) {
        auto point = bfsQueue.front();
        bfsQueue.pop_front();

        for(int cnt = 0; cnt < 4; cnt++) {
            int spreadX = point.x + dx[cnt];
            int spreadY = point.y + dy[cnt];
            struct XY spreadPoint = {spreadX, spreadY};

            if(spreadX >= 0 && spreadX < n && spreadY >= 0 && spreadY < m) {
                if(simulateMap[spreadX][spreadY] == 0) {
                    bfsQueue.push_back(spreadPoint);
                    simulateMap[spreadX][spreadY] = 2;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(simulateMap[i][j] == 0){
                shelterSize++;
            }
        }
    }
    return shelterSize;
}

void buildWall(int n, int m, int wallCnt, int **(&cloneMap), int &result) {
    if(wallCnt == 3) {
        int size = simulateVirusGetSize(n, m, cloneMap);
        if (size > result)
            result = size;
        return ;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cloneMap[i][j] == 0) {
                cloneMap[i][j] = 1;
                // WARN 주의 wallCnt++하면 큰일남. buildWall 끝난 후에 wallCnt는 다시 돌아와야하기 때문
                buildWall(n, m, wallCnt + 1, cloneMap, result);
                cloneMap[i][j] = 0;
            }
        }
    }
}

int solution(int n, int m) {
    int **map;
    int **cloneMap;
    int maxShelterSize = 0;

    initMap(n, m, map);
    initMap(n, m, cloneMap);
    setMap(n, m, map);
    deepCopyMap(n, m, map, cloneMap);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(cloneMap[i][j] == 0) {
                cloneMap[i][j] = 1;
                buildWall(n, m, 1, cloneMap, maxShelterSize);
                cloneMap[i][j] = 0;
            }
        }
    }

    return maxShelterSize;
}

int main() {
    int n,m;
    cin >> n >> m;

    cout << solution(n, m);
    return 0;
}