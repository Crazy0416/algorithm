#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Point {
    int x_;
    int y_;
};

int manhattanDist(const Point prevLoc, const Point nextLoc) {
    return (abs(prevLoc.x_ - nextLoc.x_) + abs(prevLoc.y_ - nextLoc.y_));
}

void DFS(int n, vector<Point> map, bool visit[], int visitIdx) {
    visit[visitIdx] = true;

    for(int i = 1; i < n + 2; i++) {

        if(!visit[i]) {
            int dist = manhattanDist(map[visitIdx], map[i]);

            if(dist <= 1000) {
                DFS(n, map, visit, i);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;  // 편의점 개수
        bool visit[103];
        vector<Point> map;
        memset(visit, false, sizeof(visit));

        cin >> n;

        for(int j = 0; j < n+2; j++) {
            Point conven_;
            cin >> conven_.x_ >> conven_.y_;
            map.push_back(conven_);
        }

        DFS(n, map, visit, 0);

        cout << (visit[n + 1] ? "happy" : "sad") << endl;
    }
    return 0;
}