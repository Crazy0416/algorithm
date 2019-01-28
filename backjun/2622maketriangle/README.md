# 2622 삼각형 만들기

## 시간초과 코드
```
#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0;
vector<int> triangle;

void dfs(int depth) {
    if(depth == 2) {
        int dump = 0;
        for(int i = 1; i < 3; i++)
            dump += triangle[i];

        if(N - dump < triangle[2])
            return;

        triangle.push_back(N - dump);

        if(triangle[3] < triangle[1] + triangle[2])
            cnt++;

        triangle.pop_back();
        return;
    }

    for(int i = triangle[depth]; i < N; i++) {
        triangle.push_back(i);
        dfs(depth + 1);
        triangle.pop_back();
    }
}

int main() {
    cin >> N;
    triangle.push_back(0);
    dfs(0);
    cout << cnt;

    return 0;
}
```
- 너무 어렵게 생각해서 틀렸다.

## 정답 코드
```
#include <iostream>

using namespace std;

int N;
int cnt = 0;


int main() {
    cin >> N;

    for(int i = 1; i < N - 1; i++) {
        for(int j = i; j < N; j++) {
            int k = N - i - j;
            if(k < j) break;
            if(k < i + j) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
```