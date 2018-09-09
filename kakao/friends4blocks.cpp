#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool checkBombthisTurn(int m, int n, vector<string> &board, int &answer) {
    bool **willDeletethisTurn = new bool*[m];
    bool checkRepeat = false;

    for(int i = 0; i < m; i++){
        willDeletethisTurn[i] = new bool[n];
        for(int j = 0; j < n; j++)
            willDeletethisTurn[i][j] = false;
    }

    for(int i = 0; i < m-1; i++) {
        for(int j = 0; j < n-1; j++) {
            if(board[i][j] == board[i+1][j])
                if(board[i][j] == board[i][j+1])
                    if(board[i][j] == board[i+1][j+1])
                        if((board[i][j] != ' ') && (board[i+1][j] != ' ') && (board[i][j+1] != ' ') && (board[i+1][j+1] != ' ') ) {
                            willDeletethisTurn[i][j] = true;
                            willDeletethisTurn[i][j + 1] = true;
                            willDeletethisTurn[i + 1][j] = true;
                            willDeletethisTurn[i + 1][j + 1] = true;
                            checkRepeat = true;
                        }
        }
    }
    if(!checkRepeat)
        return false;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (willDeletethisTurn[i][j]){
                answer++;
                for(int k = i; k > 0; k--) {
                    board[k][j] = board[k-1][j];
                    if(k == 1){
                        board[k-1][j] = ' ';
                    }
                }
            }
        }
    }

    for(int i = 0; i < m; i++) {    // 메모리 해제
        delete[] willDeletethisTurn[i];
    }

    return true;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (checkBombthisTurn(m, n, board, answer)) {}

    return answer;
}

int main() {
    vector<string> board;
    board.push_back("CCBDE");
    board.push_back("AAADE");
    board.push_back("AAABF");
    board.push_back("CCBBF");
    cout << solution(4, 5, board);
    return 0;
}