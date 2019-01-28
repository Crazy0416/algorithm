# 백준 2156 포도주 시식

## 해결 아이디어

- [백준 2579 계단 오르기](https://github.com/Crazy0416/algorithm/tree/master/backjun/2579stairOruegi)와 매우 유사
- 주의할 점: i-2에서 i-1로 오고 i칸을 안마시는 경우도 있기 때문에 ```dp[i][1] = max(dp[i-1][0], max(dp[i-2][0] + wines[i], dp[i-2][1] + wines[i]));```.
