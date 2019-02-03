# 프로그래머스 고득점 kit 스택/큐 프린터
- [문제 링크](https://programmers.co.kr/learn/courses/30/lessons/42587)

## 해결 아이디어

### 내 아이디어
- priority vector의 데이터들을 deque printQue로 옮김
- printQue의 최대값을 max_value 변수에 저장
- printQue의 데이터가 모두 사라질 때까지 반복문 시작
    - deque 맨 처음 데이터를 pop한 뒤에 그 데이터가 max_value인지 확인
    - max_value가 아니라면 pop한 데이터를 deque 뒤에 다시 넣는다.
    - max_value라면 answer++ 하고 deque의 최대값을 다시 찾는다. 만약 pop한 값이 location이라면 반복문 종료.
    - 위의 반복문을 반복한다.
- 핵심 알고리즘
    ```cpp
    while(printQue.size() != 0) {
         int priority = printQue.front();
         printQue.pop_front();
         location--;

         if(priority < max_value) {
             printQue.push_back(priority);
             if(location == -1)
                 location  = static_cast<int>(printQue.size() - 1);

         } else if (priority == max_value) {     // pop한 데이터가 큐의 최대 값이면
             answer++;

             if(location == -1)       // 반복문 종료 조건
                 break;

             max_value = getMaxValue(printQue);  // 다시 최대값 설정 후 반복문 실행.
         }
     }
    ```

### 다른 사람의 아이디어
- 해결1
    ```cpp
    int solution(vector<int> priorities, int location) {
        queue<int> printer;                         //queue에 index 삽입.
        vector<int> sorted;                         //정렬된 결과 저장용

        for(int i=0; i<priorities.size(); i++) {    // priorities의 인덱스를 printer에 옮김
            printer.push(i);
        }

        while(!printer.empty()) {
            int now_index = printer.front();
            printer.pop();

            // max_element: 최대값의 iterator를 반환
            if(priorities[now_index] != *max_element(priorities.begin(),priorities.end())) {
                //아닌경우 push
                printer.push(now_index);
            } else {
                //맞는경우
                sorted.push_back(now_index);    // 크기가 큰 순서대로 인덱스를 저장.
                priorities[now_index] = 0;      // 선택한 값은 priority에서 0으로 변경해 최대값 후보에서 삭제.
            }
        }
        for(int i=0; i<sorted.size(); i++) {
            if(sorted[i] == location) return i+1;
        }
    }
    ```
