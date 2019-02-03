#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int ironStack = 0;

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

    return answer;
}

int main() {
    string arrangement;
    cin >> arrangement;

    cout << solution(arrangement) << endl;
    return 0;
}