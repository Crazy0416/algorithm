#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int getMaxValue(deque<int> printQue) {
    int max_value = 0;
    for(auto iter = printQue.begin(); iter != printQue.end(); iter++)
        if(max_value < *iter)
            max_value = *iter;

    return max_value;
}

void copyDataAndGetMax(const vector<int>& priorities, deque<int>& printQue, int& max_value) {
    for(auto iter = priorities.begin(); iter != priorities.end(); iter++) {
        printQue.push_back(*iter);
        if (max_value < *iter)
            max_value = *iter;
    }
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max_value = 0;              // 대기열 중 가장 큰 값.
    deque<int> printQue;            // 대기열 큐

    copyDataAndGetMax(priorities, printQue, max_value);

    while(printQue.size() != 0) {
        int priority = printQue.front();
        printQue.pop_front();
        location--;

        if(priority < max_value) {
            printQue.push_back(priority);
            if(location == -1)
                location  = static_cast<int>(printQue.size() - 1);

        } else if (priority == max_value) {     // pop한 데이터가 큐의 최대 값이면
            answer++;

            if(location == -1)       // 반복문 종료 조건
                break;

            max_value = getMaxValue(printQue);  // 다시 최대값 설정 후 반복문 실행.
        }
    }

    return answer;
}

int main() {
    vector<int> priorities;
    int location;

    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(9);
    priorities.push_back(1);
    priorities.push_back(1);
    priorities.push_back(1);
    location = 0;


    cout << solution(priorities, location) << endl;
}