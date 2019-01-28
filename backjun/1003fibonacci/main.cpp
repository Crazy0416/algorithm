#include <iostream>

using namespace std;

int T, N;
int zdp[41] = {0,};
int odp[41] = {0,};

void fibonacci(int n) {
    zdp[0] = 1;
    odp[1] = 1;
    for(int i = 2; i <= n; i++) {
        odp[i] = odp[i-1] + odp[i-2];
        zdp[i] = zdp[i-1] + zdp[i-2];
    }
}

int main() {
    cin >> T;

    while(T--) {
        cin >> N;
        fibonacci(N);
        cout << zdp[N] << " " << odp[N] << endl;
        fill_n(zdp, 41, 0);
        fill_n(odp, 41, 0);
    }
    return 0;
}