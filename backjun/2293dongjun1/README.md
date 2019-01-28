# 백준 2293 동전1

## 해결 알고리즘

- d(i,k) : i 번째 코인을 사용하여 k를 만들 수 있는 경우의 수
- ci는 i 번째 코인의 가치(ex 1원이면 1)
- 따라서 d(i, k)는 (k < ci) 일때 d(i-1, k) 이거나 (k >= ci)일 때 d(i-1, k) + d(i, k - ci) 이다.
- 핵심 알고리즘
    ```
    dp[0] = 1;

        for(int i = 0; i < coins.size(); i++) {
            for(int k = 1; k <= K; k++) {
                if(k >= coins[i]) {
                    dp[k] += dp[k - coins[i]];
                }
            }
        }
    ```