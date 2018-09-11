#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

const int NOT_CACHE_TIME = 5;
const int CACHE_TIME = 1;

using namespace std;

class MyLRU {
public:
    int cacheSize;
    list<string> cacheList;
    unordered_map<string, list<string>::iterator> ma;
    MyLRU(int size) {
        this->cacheSize = size;
    }
    int calculatePutTime(string data) {
        int time;

        if(ma.find(data) == ma.end()) {
            if(cacheList.size() == cacheSize && cacheSize != 0) {
                string last = cacheList.back();
                cacheList.pop_back();
                ma.erase(last);
            } else if(cacheSize == 0) {
                time = NOT_CACHE_TIME;
                return time;
            }
            time = NOT_CACHE_TIME;
        } else {
            cacheList.erase(ma[data]); time = CACHE_TIME;
        }

        cacheList.push_front(data);
        ma[data] = cacheList.begin();

        return time;
    }
};


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    MyLRU myLRU(cacheSize);
    auto iter = cities.begin();


    for(; iter != cities.end(); iter++) {
        string data = *iter;
        transform(data.begin(), data.end(), data.begin(), ::tolower);

        answer += myLRU.calculatePutTime(data);
    }

    return answer;
}

int main(){
    std::cout<<"Hello, World!"<<std::endl;
    return 0;
}