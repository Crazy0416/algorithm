#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void showData(map<string, int> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++) {
        cout << iter->first <<  " " << iter->second << endl;
    }
    cout << endl;
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> kinds;

    for(auto iter = clothes.begin(); iter != clothes.end(); iter++) {
        string kind = iter->at(1);
        auto kindsIter = kinds.find(kind);
        if(kindsIter != kinds.end()) {
            // 이미 종류가 있을 때
            kindsIter->second += 1;
        } else {
            kinds.insert(make_pair(kind, 2));
        }
    }

    for(auto iter = kinds.begin(); iter != kinds.end(); iter++)
        answer *= iter->second;

    return answer - 1;
}

int main() {
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes);
    return 0;
}