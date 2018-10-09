#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<vector<bool>> map(64, vector<bool>(64, false));

bool checkSame(int x, int y, int num) {
    for(int i = x; i < x + num; i++) {
        for(int j = y; j < y + num; j++) {
            if(map[i][j] != map[x][y])
                return false;
        }
    }

    return true;
}

string quadTree(int x, int y, int num) {
    if(checkSame(x, y, num) || num == 1) {
        return (map[x][y] == 1) ? "1" : "0";
    } else {
        string result = "(";
        int divNum = num / 2;
        result += quadTree(x, y, divNum);
        result += quadTree(x, y + divNum, divNum);
        result += quadTree(x + divNum, y, divNum);
        result += quadTree(x + divNum, y + divNum, divNum);
        result += ")";

        return result;
    }
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            char dump; cin >> dump;
            map[i][j] = (dump == '1');
        }
    }

    cout << quadTree(0, 0, N);

    return 0;
}