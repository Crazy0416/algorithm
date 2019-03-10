# 프로그래머스 고득점 kit 스택/큐 주식 가격

## 해결 아이디어

- 거꾸로 prices를 순회하면서 각 주식이 얼마나 유지되는 지 또 다시 반복문을 통해 알아본다.
- 핵심 알고리즘
  ```
  vector<int> solution(vector<int> prices) {
      vector<int> answer;

      for(int idx = prices.size() - 1; idx != -1; idx--) {
          int price = prices.at(idx);
          int continuous = 0;
          for(int i = idx + 1; i < prices.size(); i++) {
              continuous++;
              if(prices.at(i) < price) {
                  break;
              }
          }
          answer.push_back(continuous);
      }

      reverse(answer.begin(), answer.end());

      return answer;
  }
  ```