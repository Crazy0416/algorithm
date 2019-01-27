#include <iostream>
#include <list>

using namespace std;

int main() {
    long long N, B, C;
    list<long long> A;
    long long result = 0;

    cin >> N;
    for(int i = 0; i < N; i++) {
        long long dump;
        cin >> dump;
        A.push_back(dump);
    }
    cin >> B >> C;

    while (A.size()) {
        result += 1;
        long long candidateCnt = A.front();
        A.pop_front();
        candidateCnt -= B;

        if(candidateCnt > 0) {
            long long dump = (long long)((long long)candidateCnt / C);
            result += (long long)dump;

            dump = candidateCnt % C;
            if(dump != 0)
                result++;
        }
    }
    printf("%lld", result);


    return 0;
}