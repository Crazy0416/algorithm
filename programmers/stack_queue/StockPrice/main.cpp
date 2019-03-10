#include <iostream>
#include <string>
#include <vector>

using namespace std;

void showData(vector<int> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int idx = prices.size() - 1; idx != -1; idx--) {
        int price = prices.at(idx);
        int continuous = 0;
        for(int i = idx + 1; i < prices.size(); i++) {
            continuous++;
            if(prices.at(i) < price) {
                break;
            }
        }
        answer.push_back(continuous);
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<int> prices = {1, 2, 3, 2, 3};
    showData(solution(prices));
    return 0;
}