# 프로그래머스 고득점 kit 해시 가장 큰

## 해결 아이디어

- 처음에는 이렇게 비교했다.
    - a의 첫자리와 b의 첫자리가 다르다면 큰 쪽이 배열 앞으로 정렬되도록 한다.
    - 둘 다 같다면 a와 b의 자리 수를 맞추기 위해 작은 수에 0을 추가로 반복문으로 붙인다.
      ex) a = '11', b = '1'일때 b = '10'으로 만든다.
      그 후에 a와 b를 비교한다.

- 하지만 그런 비교 방식은 반복문에 의해 시간이 오래걸렸다.
- 다른 해결책 a와 b를 합친 문자열과 b와 a를 합친 문자열을 비교한다.
- 핵심 알고리즘
  ```
  bool comp(int a, int b) {
      string as = to_string(a);
      string bs = to_string(b);

      if(bs + as < as + bs)
          return true;
      else
          return false;
  }
  ```