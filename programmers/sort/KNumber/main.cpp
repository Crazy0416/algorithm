#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(auto iter = commands.begin(); iter != commands.end(); iter++) {
        int i = iter->at(0);
        int j = iter->at(1);
        int k = iter->at(2);
        vector<int> dump;

        for(int idx = i - 1; idx < j; idx++) {
            dump.push_back(array[idx]);
        }

        sort(dump.begin(), dump.end());

        answer.push_back(dump.at(k - 1));
    }

    return answer;
}

void showData(vector<int> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    showData(solution(array, commands));
    return 0;
}