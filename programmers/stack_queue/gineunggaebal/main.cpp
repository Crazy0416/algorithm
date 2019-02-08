#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void showVector(vector<int> vec) {
    for(auto iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int iter = 1;
    int date = (int)(ceil((double)(100 - progresses[0]) / speeds[0]));       // 날짜가 지난 수
    int deployCnt = 1;  // 한 배포당 배포 가능한 기능 수
    int duration = 0;   // 한 기능에 대한 완성 기간

    while(true) {
        if(iter == progresses.size()) {
            answer.push_back(deployCnt);
            break;
        }

        int prog = progresses[iter];
        int speed = speeds[iter];

        duration = (int)(ceil((double)(100 - prog) / speed));

        if(duration <= date) {  // 만약 현재 진행된 날짜보다 이 기능의 완성 기간이 작거나 같다면
            deployCnt++;        // 이 기능 또한 이전의 기능과 같이 배포된다.
        } else {                // 만약 현재 진행된 날짜가 더 작다면
            date = duration;
            answer.push_back(deployCnt);
            deployCnt = 1;      // 이 기능은 다음 배포에 포함된다.
        }
        iter++;
    }

    return answer;
}


int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    showVector(solution(progresses, speeds));

    return 0;
}