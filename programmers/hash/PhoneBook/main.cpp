#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

void showData(vector<string> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++) {
        cout << *iter << " ";
    }
}

void showData(map<string, vector<string>> data) {
    cout << "list: ";
    for(auto iter = data.begin(); iter != data.end(); iter++) {
        cout << iter->first << " ";
        showData(iter->second);
    }
    cout << endl;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> list;

    for(int idx = 0; idx < phone_book.size(); idx++) {
        string phone_number = phone_book[idx];

        for(int pIdx = 1; pIdx <= phone_number.size(); pIdx++) {
            string number_split = phone_number.substr(0, pIdx);
            if(list.count(number_split) == 0) {
                pair<string, int> phone_map(number_split, 1);
                list.insert(phone_map);
            } else {
                auto dump = list.find(number_split);
                dump->second += 1;
            }
        }
    }

    for(int idx = 0; idx < phone_book.size(); idx++) {
        if(list.find(phone_book[idx])->second > 1) {
            answer = false;
            break;
        }
    }

    return answer;
}

int main() {
    vector<string> phone_book = {"12232332", "12", "222222"};
    cout << solution(phone_book);
    return 0;
}