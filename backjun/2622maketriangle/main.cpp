#include <iostream>

using namespace std;

int N;
int cnt = 0;


int main() {
    cin >> N;

    for(int i = 1; i < N - 1; i++) {
        for(int j = i; j < N; j++) {
            int k = N - i - j;
            if(k < j) break;
            if(k < i + j) cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}