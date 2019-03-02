# 프로그래머스 고득점 kit 스택/큐 프린터
- [문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42588)

## 해결 아이디어

### 내 아이디어
- 스택을 사용하기도 뭐한 문제
- 간단히 heights의 마지막 item부터 검사하여 차례대로 answer의 값을 push_back 해주거나 값을 직접 대입하면 된다.t

- 핵심 알고리즘
    ```
    // cur_iter가 끝날 때까지 answer를 결정하는 함수 반복
        for(;answer_iter != -1; answer_iter--) {
            int cur_height = heights.at(answer_iter);
            int cur_idx = -1;

            // cur_iter 위치의 answer 값을 결정하는 함수
            for(int idx = answer_iter - 1; idx >= 0; idx--) {
                if (cur_height < heights.at(idx)) {
                    cur_idx = idx;
                    break;
                }
            }

            answer[answer_iter] = (cur_idx != -1) ? cur_idx + 1 : 0;
        }
    ```