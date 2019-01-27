# 백준 2667 단지번호 붙이기

## 해결 알고리즘

- 이중 포문으로 map에서 1을 만나게 되면 bfs 함수를 실행한다. (dfs로도 가능)

- bfs 함수는 한 단지에 속해있는 집 수를 점차 늘리면서 map에서 1의 값을 지운다.

- 따라서 bfs 함수를 전부 돌게 되면 한 단지의 집 수를 vector에 push_back 한 뒤 다음 단지를 향하기 위해 bfs를 종료한다.

- 메인 알고리즘 

  ```
  void eraseApart(int **&map, int N, int i, int j, vector<int>& apartInfo) {
      queue<pair<int, int>> bfs;
  
      int dx[] = {-1, 1, 0, 0};	// 4 방향으로 가기 위한 배열
      int dy[] = {0, 0, -1, 1};	// 위의 배열과 같이 쓰임
  
      bfs.push(pair<int, int>(i, j));
      int danziCnt = 0;
  
      do{
          pair<int, int> data = bfs.front();
          bfs.pop();
          if(map[data.first][data.second] == 0)	// 중복 넘어감
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
  ```

  