# 백준 9205 맥주 마시면서 걸어가기

## 해결 아이디어

- DFS로 해결

- DFS는 한 위치에서 다음 위치로 방문 할 수 있다면 다음 위치에서 DFS를 실행하여 또 다음 위치를 찾아간다.

- 다음 위치로 방문할 경우 visit을 true로 바꾸어 또 다음 위치를 찾을 시에 중복되지 않게 한다.

- 핵심 알고리즘

  ```
  void DFS(int n, vector<Point> map, bool visit[], int visitIdx) {
      visit[visitIdx] = true;
  
      for(int i = 1; i < n + 2; i++) {
  
          if(!visit[i]) {
              int dist = manhattanDist(map[visitIdx], map[i]);
  
              if(dist <= 1000) {
                  DFS(n, map, visit, i);
              }
          }
      }
  }
  
  ```

  