# 백준 1149 RGB 거리

## 해결 아이디어

- 다이나믹 프로그래밍
- i번째 집에 색을 칠할 때 최소 값을 dp에 메모라이즈 한다.
- RGB 세가지 색만 존재하기 때문에 각 색에 대한 최소값을 정해줘야 한다. 어떤 색으로 시작하느냐에 따라 최소값이 다르기 때문이다.
- 따라서 dp\[i\]\[0\], dp\[i\]\[1\], dp\[i\]\[2\]에 대해 i값을 증가시키며 값을 정해야한다.
- 메인 알고리즘
    ```
    void solution() {
        for(int i = 1; i <= N; i++) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);  // 0은 R
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);  // 1은 G
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);  // 2은 B
        }

        cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << endl;
    }
    ```