#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size(), 0);
    int answer_iter = heights.size() - 1;  // heights의 맨 마지막 item부터 내려간다.

    // cur_iter가 끝날 때까지 answer를 결정하는 함수 반복
    for(;answer_iter != -1; answer_iter--) {
        int cur_height = heights.at(answer_iter);
        int cur_idx = -1;

        // cur_iter 위치의 answer 값을 결정하는 함수
        for(int idx = answer_iter - 1; idx >= 0; idx--) {
            if (cur_height < heights.at(idx)) {
                cur_idx = idx;
                break;
            }
        }

        answer[answer_iter] = (cur_idx != -1) ? cur_idx + 1 : 0;
    }

    return answer;
}

void showData(const vector<int> data) {
    for(int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {6,9,5,7,4};
    vector<int> result = solution(data);
    showData(result);

    return 0;
}