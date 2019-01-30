# 백준 9506 약수들의 합

# 해결 아이디어

- 어떤 수 N의 약수를 구하는 알고리즘
    ```
    for(int i = 1; i <= maxCnt; i++) {
            if(N % i == 0) {
                myMeasure.push_back(i);     // 약수들을 저장하는 vector
                myMeasure.push_back(N / i);
            }
        }
    ```