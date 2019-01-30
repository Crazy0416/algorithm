#include <iostream>

using namespace std;

int N;
int *column;
int COUNT = 0;

void initMap() {
    column = new int[N];
    fill_n(column, N, 0);
}

bool check(int idx) {
    for(int i = 0; i < idx; i++) {
        int differ = idx - i;

        if(column[idx] == column[i])
            return false;
        if(column[idx] == column[i] - differ)
            return false;
        if(column[idx] == column[i] + differ)
            return false;
    }
    return true;
}

void dfs(int idx) {
    if(idx == N) {
        COUNT++;
        return;
    }

    for(int i = 0; i < N; i++) {
        column[idx] = i;
        if(check(idx))
            dfs(idx + 1);
        //column[idx] = 0;
    }
}


int main() {
    cin >> N;
    initMap();

    dfs(0);

    cout << COUNT << endl;
    return 0;
}