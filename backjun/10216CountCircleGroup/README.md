# 백준 10216 Count Circle Groups

## 해결 아이디어

- BFS를 이용함.

- ```map<int, enemyBase> baseInfos``` 에 적 기지의 정보를 저장. (enemyBase는 위치 x, y와 범위 r을 갖는 구조체)

- 먼저 ```baseInfos```가 전부 사라질 때까지 반복문을 돈다. 그 안에서 BFS를 돌린다.

- BFS는 한 개의 기지와 연결된 기지들을 찾아가며 ```baseInfos```에서 그룹지어진 기지들을 전부 삭제한다.

- BFS가 종료되면 baseInfos에 남은 기지를 하나 골라 또 다시 그룹을 지은 뒤 그룹지어진 기지들을 삭제한다.

- 그룹을 지울 때 ```baseCnt``` 를 증가시키며 그룹의 수를 센다.

- 핵심 알고리즘

  ```c++
  void makeBasesGroup() {
      int baseCnt = 0;
      queue<int> bfsQueue;
  
      while(baseInfos.size() > 0){
          set<int> visit;
          visit.insert((*baseInfos.begin()).first);
          bfsQueue.push((*baseInfos.begin()).first);
  
          while(bfsQueue.size() > 0) {
              int baseNum = bfsQueue.front();
              auto compareBase = (*baseInfos.find(baseNum)).second;
              bfsQueue.pop();
  
              auto iter = baseInfos.begin();
  
              for(; iter != baseInfos.end(); iter++) {
                  if(checkGroup((*iter).second, compareBase) && (visit.find((*iter).first) == visit.end())) {
                      bfsQueue.push((*iter).first);
                      visit.insert((*iter).first);
                  }
              }
              baseInfos.erase(baseNum);
              visit.erase(baseNum);
          }
          baseCnt++;
          while(!bfsQueue.empty())
              bfsQueue.pop();
      }
  
      cout << baseCnt << endl;
  }
  ```

  