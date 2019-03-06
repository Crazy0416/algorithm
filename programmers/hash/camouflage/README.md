# 프로그래머스 고득점 kit 해시 위장

## 해결 아이디어

- 먼저 분류별로 옷들의 수를 알아내기 위해 map<string, int> kinds 변수를 선언, ['옷 종류 이름', '옷의 수']를 저장한다.
- 옷 종류마다 (0, 1, 2, ... '옷의 수')의 경우의 수를 가질 수 있다.
- 그리고 모든 옷 종류가 선택되지 않는 경우의 수 1을 빼야한다.
- 따라서 옷 종류를 K, 옷 종류의 수는 k개가 있고 i (1 <= i <= k) 종류의 옷마다 가지고 있는 옷의 수를 Ki라고 할 떄,
  answer = (K1 + 1) * (K2 + 1) * ... * (Kk + 1) - 1; 이다.

  ```
  for(auto iter = clothes.begin(); iter != clothes.end(); iter++) {
      string kind = iter->at(1);
      auto kindsIter = kinds.find(kind);
      if(kindsIter != kinds.end()) {
          // 이미 종류가 있을 때
          kindsIter->second += 1;
      } else {
          kinds.insert(make_pair(kind, 2));
      }
  }

  for(auto iter = kinds.begin(); iter != kinds.end(); iter++)
      answer *= iter->second;

  return answer - 1;
  ```