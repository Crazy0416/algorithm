#include <string>
#include <vector>
#include <iostream>
#include <bitset>

using namespace std;

void changeStringtoBoolLine(bool **mapLine, int n, int line, string bin1, string bin2) {
    int binLen = bin1.size();

    for(int i = 0; i < n; i++) {
        bool checkTrueorFalse1 = (bin1[binLen - i - 1] == '0')? false : true;
        bool checkTrueorFalse2 = (bin2[binLen - i - 1] == '0')? false : true;

        if(checkTrueorFalse1)
            mapLine[line][n - i - 1] = true;
        if(checkTrueorFalse2)
            mapLine[line][n - i - 1] = true;
    }
}

string makeMaptoString(bool *mapLine, int n) {
    string line;
    for(int i = 0; i < n; i++) {
        if(mapLine[i])
            line += '#';
        else
            line += ' ';
    }
    return line;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    bool **mapArr = new bool*[n];

    for(int i = 0; i < n; i++) {
        mapArr[i] = new bool[n];
        for(int j = 0; j < n; j++) {
            mapArr[i][j] = false;
        }
    }

    // 지도 한 줄씩 mapArr을 채워나감
    for(int i = 0; i < n; i++) {
        string map1LineStr = bitset<17>(arr1[i]).to_string();
        string map2LineStr = bitset<17>(arr2[i]).to_string();

        changeStringtoBoolLine(mapArr, n, i, map1LineStr, map2LineStr);
        string line = makeMaptoString(mapArr[i], n);

        answer.push_back(line);
    }



    return answer;
}

int main() {
    vector<int> arr1 = 	{9, 20, 28, 18, 11};
    vector<int> arr2 = 	{30, 1, 21, 17, 28};
    int n = 5;

    vector<string> temp = solution(n, arr1, arr2);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << temp[i][j];
        cout << endl;
    }

}