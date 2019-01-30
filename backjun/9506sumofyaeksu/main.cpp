#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> myMeasure;

void showAnswer() {
    int maxCnt = (int) sqrt((double) N);
    int mySum = 0;

    for(int i = 1; i <= maxCnt; i++) {
        if(N % i == 0) {
            myMeasure.push_back(i);
            myMeasure.push_back(N / i);
        }
    }

    sort(myMeasure.begin(), myMeasure.end());
    myMeasure.pop_back();


    for(int i = 0; i < myMeasure.size(); i++)
        mySum += myMeasure[i];

    if(N == mySum) {
        cout << N << " = " << myMeasure[0] << " ";
        for(int i = 1; i < myMeasure.size(); i++) {
            cout << "+ " << myMeasure[i] << " ";
        }
        cout << endl;
    } else {
        cout << N << " is NOT perfect." << endl;
    }

    myMeasure.clear();
}

int main() {

    do {
        cin >> N;

        if(N == -1)
            break;

        showAnswer();

    } while(true);

    return 0;
}