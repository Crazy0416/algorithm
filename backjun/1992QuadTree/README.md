# 백준 1992 쿼드 트리

## 해결 아이디어

- 분할 정복으로 문제를 해결한다.

- 핵심 알고리즘

  ```c++
  string quadTree(int x, int y, int num) {
      if(checkSame(x, y, num) || num == 1) {
          return (map[x][y] == 1) ? "1" : "0";
      } else {
          string result = "(";
          int divNum = num / 2;
          result += quadTree(x, y, divNum);
          result += quadTree(x, y + divNum, divNum);
          result += quadTree(x + divNum, y, divNum);
          result += quadTree(x + divNum, y + divNum, divNum);
          result += ")";
  
          return result;
      }
  }
  ```

  

