# 백준 14502 연구소

## 해결 아이디어

- 벽 3개를 맵에 전부 넣어보며 DFS를 통해 전수검사한다.
- 3개를 넣었을 때 바이러스를 퍼뜨려보아 안전영역의 크기를 구한다.
- 구한 안전 영역이 이전의 안전 영역보다 크다면 값을 저장한다.



## 주의했던 점

```
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
```

- wallCnt++ 했었다가 값이 계속 증가하여 논리 오류가 발생했다.