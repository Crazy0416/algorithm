#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void showData(vector<int> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores = {0, 0, 0};
    vector<vector<int>> supojas = {{1, 2, 3, 4, 5},
                                   {2, 1, 2, 3, 2, 4, 2, 5},
                                   {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

    for(int i = 0; i < answers.size(); i++) {
        for(int supoIdx = 0; supoIdx < 3; supoIdx++ ){
            if(supojas[supoIdx][i % supojas[supoIdx].size()] == answers[i]) {
                scores[supoIdx]++;
            }
        }
    }

    int max_score = *max_element(scores.begin(), scores.end());

    for(int supoIdx = 0; supoIdx < 3; supoIdx++ ){
        if(max_score == scores[supoIdx]) {
            answer.push_back(supoIdx + 1);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<int> answers = {1, 2, 3, 4, 5};
    showData(solution(answers));
    return 0;
}