#include <iostream>

using namespace std;


int N;
int tree[27][2];

void preOrder(int node) {
    if(node == '.' - 'A')
        return;

    cout << char(node + 'A');
    preOrder(tree[node][0]);
    preOrder(tree[node][1]);
}

void inOrder(int node) {
    if(node == '.' - 'A')
        return;

    inOrder(tree[node][0]);
    cout << char(node + 'A');
    inOrder(tree[node][1]);
}

void postOrder(int node) {
    if(node == '.' - 'A')
        return;

    postOrder(tree[node][0]);
    postOrder(tree[node][1]);
    cout << char(node + 'A');
}


int main() {
    cin >> N;

    char a, b, c;
    for(int i = 1; i <= N; i++) {

        cin >> a >> b >> c;

        tree[a - 'A'][0] = b - 'A';
        tree[a - 'A'][1] = c - 'A';
    }

    preOrder(0);
    cout << "\n";

    inOrder(0);
    cout << "\n";

    postOrder(0);

    return 0;
}