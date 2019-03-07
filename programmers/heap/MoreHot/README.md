# 프로그래머스 고득점 kit 힙 더 맵게

## 해결 아이디어

- 힙 자료구조를 사용해서 해결
- 힙에서 2개를 꺼내 새로 만든 스코빌 지수를 새로 힙 구조에 push 한다.
  - 이 행위를 반복한다.
- 힙의 최소 값이 K를 넘기면 반복문을 종료한다.
- 만약 힙 구조에 데이터가 더 이상 존재하지 않으면 return -1; 한다.
- 핵심 알고리즘
  ```
  while(true) {
      int score = scoville.front();
      if(scoville.size() == 1) {
          if(score >= K)
              break;
          else
              return -1;
      }
      if(score >= K)
          break;
      else {
          pop_heap(scoville.begin(), scoville.end(), greater<int>());
          scoville.pop_back();
          score += scoville.front() * 2;
          pop_heap(scoville.begin(), scoville.end(), greater<int>());
          scoville.pop_back();

          scoville.push_back(score);
          push_heap(scoville.begin(), scoville.end(), greater<int>());
          answer++;
      }
  }
  ```

- priority queue를 사용해서 더 간단하게 코드를 작성할 수 있다.
  ```
  priority_queue<int, vector<int>, greater<int>> sco;

  for(auto iter = scoville.begin(); iter != scoville.end(); iter++)
      sco.push(*iter);

  for(; sco.size() >= 2 && sco.top() < K; ) {
      int mix1 = sco.top();
      sco.pop();
      int mix2 = sco.top()*2;
      sco.pop();

      sco.push(mix1+mix2);
      ++answer;
  }

  if(sco.top() < K)
      answer = -1;

  return answer;
  ```
