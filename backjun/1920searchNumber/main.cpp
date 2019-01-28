#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int>& v, int x) {
    int cur_idx = 0;
    int begin_idx = 0;
    int end_idx = v.size() - 1;

    while(begin_idx <= end_idx) {
        cur_idx = ( begin_idx + end_idx ) / 2;

        if(v[cur_idx] == x) {
            return true;
        } else {
            if(v[cur_idx] > x)
                end_idx = cur_idx - 1;
            else
                begin_idx = cur_idx + 1;
        }
    }

    return false;
}

void inputVector(vector<int>& v, int size) {
    int dump;

    for(int i = 0; i < size; i++) {
        cin >> dump;
        v.push_back(dump);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    int N, M;

    cin >> N;
    vector<int> A;
    inputVector(A,N);

    cin >> M;
    vector<int> m;
    inputVector(m,M);

    sort(A.begin(), A.end());

    for(int i = 0; i < m.size(); i++) {
        cout << binarySearch(A, m[i]) << "\n";
    }

    return 0;
}