#include <iostream>
#include "MStack.h"
#include <stack>


using namespace std;

int main() {
    MStack<int> _stack;

    cout << _stack.top() << endl;

    _stack.push(1);
    _stack.push(3);
    _stack.push(21);
    cout << _stack.top() << " ";
    _stack.pop();
    cout << _stack.top() << " ";
    _stack.pop();
    cout << _stack.top() << " ";
    _stack.pop();
    cout << _stack.top() << " ";
    _stack.push(21);
    cout << _stack.top() << " ";
    _stack.push(33);
    cout << _stack.top() << " ";

    return 0;
}