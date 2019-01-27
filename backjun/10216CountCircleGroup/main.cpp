#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct enemyBase {
    int x_;
    int y_;
    int r_;
};

int T, N;
map<int, enemyBase> baseInfos;

bool checkGroup(struct enemyBase a, struct enemyBase b) {
    int x = a.x_ - b.x_;
    int y = a.y_ - b.y_;
    int r = a.r_ + b.r_;

    return ((x*x) + (y*y) <= r*r);
}

void makeBasesGroup() {
    int baseCnt = 0;
    queue<int> bfsQueue;

    while(baseInfos.size() > 0){
        set<int> visit;
        visit.insert((*baseInfos.begin()).first);
        bfsQueue.push((*baseInfos.begin()).first);

        while(bfsQueue.size() > 0) {
            int baseNum = bfsQueue.front();
            auto compareBase = (*baseInfos.find(baseNum)).second;
            bfsQueue.pop();

            auto iter = baseInfos.begin();

            for(; iter != baseInfos.end(); iter++) {
                if(checkGroup((*iter).second, compareBase) && (visit.find((*iter).first) == visit.end())) {
                    bfsQueue.push((*iter).first);
                    visit.insert((*iter).first);
                }
            }
            baseInfos.erase(baseNum);
            visit.erase(baseNum);
        }
        baseCnt++;
        while(!bfsQueue.empty())
            bfsQueue.pop();
    }

    cout << baseCnt << endl;
}

int main() {
    cin >> T;

    while(T--) {
        cin >> N;

        for(int i = 0; i < N; i++) {
            int x, y, r;
            cin >> x >> y >> r; struct enemyBase enemyBase1 = {x, y, r};
            baseInfos.insert(make_pair(i, enemyBase1));
        }
        makeBasesGroup();
        baseInfos.clear();
    }
    return 0;
}