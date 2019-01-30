# 백준 9663

## 시간 초과 오류 뜬 코드

```c++
#include <iostream>

using namespace std;

int N;
int **map;
int COUNT = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dix[] = {-1, 1, -1, 1};
int diy[] = {-1, 1, 1, -1};

void initMap() {
    map = new int*[N];

    for(int i=0; i < N; i++) {
        map[i] = new int[N];
        fill_n(map[i], N, 0);
    }
}

bool XYcheck(int x, int y) {
    for(int dIdx = 0; dIdx < 4; dIdx++ ) {
        for(int xx = x, yy = y; xx >= 0 && xx < N && yy >= 0 && yy < N; xx += dx[dIdx],  yy += dy[dIdx] ) {
            if(xx == x && yy == y)
                continue;
            if(map[yy][xx] >= 1) {
                return false;
            }
        }
    }
    for(int dIdx = 0; dIdx < 4; dIdx++ ) {
        for(int xx = x, yy = y; xx >= 0 && xx < N && yy >= 0 && yy < N; xx += dix[dIdx],  yy += diy[dIdx] ) {
            if(xx == x && yy == y)
                continue;
            if(map[yy][xx] >= 1) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int idx) {
    if(idx == N) {
        COUNT++;
        return;
    }
    for(int i = 0; i < N; i++) {
        map[i][idx] = 1;
        if(XYcheck(idx, i)) {
            dfs(idx + 1);
        }
        map[i][idx] = 0;
    }
}


int main() {
    cin >> N;
    initMap();

    dfs(0);

    cout << COUNT << endl;
    return 0;
}
```

- 2차원 배열 map에서 한 칸씩 움직이며 check 했기 때문에 시간이 오래걸림



## 수정한 코드

```c++
#include <iostream>

using namespace std;

int N;
int *column;
int COUNT = 0;

void initMap() {
    column = new int[N];
    fill_n(column, N, 0);
}

bool check(int idx) {
    for(int i = 0; i < idx; i++) {
        int differ = idx - i;

        if(column[idx] == column[i])
            return false;
        if(column[idx] == column[i] - differ)
            return false;
        if(column[idx] == column[i] + differ)
            return false;
    }
    return true;
}

void dfs(int idx) {
    if(idx == N) {
        COUNT++;
        return;
    }

    for(int i = 0; i < N; i++) {
        column[idx] = i;
        if(check(idx))
            dfs(idx + 1);
        //column[idx] = 0;
    }
}


int main() {
    cin >> N;
    initMap();

    dfs(0);

    cout << COUNT << endl;
    return 0;
}
```

