#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    string as = to_string(a);
    string bs = to_string(b);

    if(bs + as < as + bs)
        return true;
    else
        return false;
}


string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), comp);

    for(auto iter = numbers.begin(); iter != numbers.end(); iter++)
        answer += to_string(*iter);

    if(answer[0] == '0')
        return "0";

    return answer;
}

int main() {
    vector<int> numbers = {6, 10, 2};
    cout << solution(numbers);
    return 0;
}