#include <iostream>
#include <cstring>

using namespace std;

string f_str;
string s_str;
int dp[1001] = {0,};

void solution() {
    if (f_str.size() < s_str.size())
        swap(f_str, s_str);

    for(int i = 0; )

}

int main() {
    cin >> f_str >> s_str;
    solution();

    return 0;
}