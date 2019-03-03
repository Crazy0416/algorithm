#include <iostream>
#include "HashMap.h"

using namespace std;

int main() {
    HashMap<int, string> testMap;

    testMap.insert(1, "test1");
    testMap.insert(11, "test11");

    cout << testMap.find(11);
    return 0;
}