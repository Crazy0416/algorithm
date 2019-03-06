#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void showData(vector<pair<int, string>> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++ ) {
        cout << iter->second << " " << iter->first << endl;
    }
    cout << endl;
}

void showData(multimap<string, pair<int, int>> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++ ) {
        cout << iter->first << iter->second.first << " " << iter->second.second << endl;
    }
    cout << endl;
}

void showData(vector<int> data) {
    for(auto iter = data.begin(); iter != data.end(); iter++ ) {
        cout << *iter << " ";
    }
    cout << endl;
}

// pair<int, int>를 정렬하기 위한 함수
// pair<음악 재생 횟수, 음악 고유 넘버>로 저장되어 있다.
bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first)
        return true;
    else if(a.first == b.first) {
        return a.second < b.second;
    } else
        return false;

}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genresCntMap;
    multimap<string, pair<int, int>> playListData;

    // plays와 genres를 순회하여 genresCntMap과 playListData에 데이터 저장.
    for(int idx = 0; idx < genres.size(); idx++) {
        auto play_idx_pair = make_pair(plays[idx], idx);
        playListData.insert(make_pair(genres[idx] ,play_idx_pair));
        genresCntMap[genres[idx]] += plays[idx];
    }

    // map to vector and sort
    vector<pair<int, string>> genresCntVector;

    // genresCntMap의 데이터를 genresCntVector로 옮겨 소팅하기 위함.
    for(auto iter = genresCntMap.begin(); iter != genresCntMap.end(); iter++) {
        genresCntVector.push_back(make_pair(iter->second, iter->first));
    }
    sort(genresCntVector.rbegin(), genresCntVector.rend());

    // genre의 순서대로 genre를 추출해 answer에 음악 idx를 삽입할 것임.
    for(auto genIter = genresCntVector.begin(); genIter != genresCntVector.end(); genIter++) {
        string genre = genIter->second;
        auto play_i_iter = playListData.equal_range(genre);

        vector<pair<int, int>> dump;
        for(auto iter = play_i_iter.first; iter != play_i_iter.second; iter++) {
            dump.push_back(make_pair(iter->second.first, iter->second.second));
        }

        sort(dump.begin(), dump.end(), comp);

        int cnt = 0;
        for(auto iter = dump.begin(); iter != dump.end(); iter++, cnt++) {
            // 2개 이상이면 다음 장르로 넘어감.
            if(cnt == 2) break;
            answer.push_back(iter->second);
        }
    }

    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 500, 500, 500, 500};

    showData(solution(genres, plays));

    return 0;
}