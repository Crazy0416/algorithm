#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v(9);
    int dump;
    int max = 0, idx = 0;

    for(int i = 0; i < 9; i++) {
        cin >> dump;
        v.push_back(dump);

        if(max < dump) {
            max = dump;
            idx = i + 1;
        }
    }

    cout << max << endl
        << idx << endl;

    return 0;
}