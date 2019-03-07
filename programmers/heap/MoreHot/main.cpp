#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void showData(vector<int> data) {
    for(int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> sco;

    for(auto iter = scoville.begin(); iter != scoville.end(); iter++)
        sco.push(*iter);

    for(; sco.size() >= 2 && sco.top() < K; ) {
        int mix1 = sco.top();
        sco.pop();
        int mix2 = sco.top()*2;
        sco.pop();

        sco.push(mix1+mix2);
        ++answer;
    }

    if(sco.top() < K)
        answer = -1;

    return answer;
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << "answer: " << solution(scoville, K) << endl;
    return 0;
}