# 프로그래머스 고득점 kit 전수 검사 모의 고사

## 해결 아이디어

- 그냥 전수 검사
- 하지만 코드의 반복은 싫어하기 때문에 반복 패턴을 이차원 벡터에 저장.
- 수포자의 정답 찍기 패턴이 반복되기 때문에 문제와 비교하기 위해서 modular 연산이 필요
    - ```supojas[supoIdx][i % supojas[supoIdx].size()] == answers[i]```
- 핵심 알고리즘
  ```
  for(int i = 0; i < answers.size(); i++) {
      for(int supoIdx = 0; supoIdx < 3; supoIdx++ ){
          if(supojas[supoIdx][i % supojas[supoIdx].size()] == answers[i]) {
              scores[supoIdx]++;
          }
      }
  }

  int max_score = *max_element(scores.begin(), scores.end());

  for(int supoIdx = 0; supoIdx < 3; supoIdx++ ){
      if(max_score == scores[supoIdx]) {
          answer.push_back(supoIdx + 1);
      }
  }

  sort(answer.begin(), answer.end());
  return answer;
  ```