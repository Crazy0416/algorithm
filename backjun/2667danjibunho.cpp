#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> myMap(25, vector<int>(25, false));
vector<int> complexCnts;
int N;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void groupApart(int x, int y, int num) {
    if(x < 0 || x >= N || y < 0 || y >= N)
        return;
    else if (myMap[x][y] != 1){
        return;
    }
    else {
        myMap[x][y] = 0;
        complexCnts[num]++;

        for(int cnt = 0; cnt < 4; cnt++)
            groupApart(x + dx[cnt], y + dy[cnt], num);
    }
}

void makeComplex() {
    int num = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(myMap[i][j] == 1) {
                complexCnts.push_back(0);
                groupApart(i, j, num); num++;
            }
        }
    }
}


int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            char t; cin >> t;
            myMap[i][j] = atoi(&t);
        }
    }

    makeComplex();

    cout << complexCnts.size() << endl;

    sort(complexCnts.begin(), complexCnts.end());
    for(int i = 0; i < complexCnts.size(); i++) {
        cout << complexCnts[i] << endl;
    }


    return 0;
}