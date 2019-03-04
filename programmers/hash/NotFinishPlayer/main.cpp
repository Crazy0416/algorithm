#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void showData(vector<string> data) {
    for(int i = 0; i < data.size(); i++) {
        cout << data.at(i) << " ";
    }
    cout << endl;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    showData(participant);
    showData(completion);

    for(int idx = 0; idx < completion.size(); idx++) {
        if(participant.at(idx) != completion.at(idx)) {
            answer = participant.at(idx);
            cout << idx << endl;
            break;
        }
    }

    answer = (answer == "") ? *(--participant.end()) : answer;
    return answer;
}

int main() {
    vector<string> part = {"mislav", "stanko", "mislav", "ana"};
    vector<string> comp = {"mislav", "ana", "mislav"};
    cout << solution(part, comp) << endl;
    return 0;
}