# 프로그래머스 고득점 kit 스택/큐 철막대기

- [문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42585)

# 해결 아이디어

- 현재 잘려진 쇠막대기 개수를 answer, 현재 쌓여있는 쇠막대기 개수를 ironStack이라고 하자.
- 레이저 포인터가 쏘일 때마다 현재 쌓여있는 쇠막대기 개수만큼 answer가 증가한다.
- 쇠막대기의 길이가 끝나는 지점 ')'이 있을 때마다 answer가 1 증가한다.
- 따라서 핵심 알고리즘은 다음과 같다.
    ```
    for(int idx = 0; idx < arrangement.size(); idx++) {
            char ch = arrangement[idx];

            if(ch == '(')
                ironStack++;
            if(ch == ')') {
                if(arrangement[idx - 1] == '(') {   /// 레이저 포인터인 경우
                    ironStack--;
                    answer += ironStack;
                } else {                            /// 철막대기가 끝난 경우
                    ironStack--;
                    answer++;
                }
            }
        }
    ```