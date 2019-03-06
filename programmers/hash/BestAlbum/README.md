# 프로그래머스 고득점 kit 해시 베스트 앨범

## 해결 아이디어

- 멀티맵을 사용하여 키의 다치값을 저장
- playListData는 문제에서 원하는 음악 순서대로 음악을 저장하기 위한 멀티맵이다.
- genresCntMap과 genresCntVector는 장르의 순서를 알기 위해 사용한 자료구조이다.
- 핵심 코드
  ```
  vector<int> answer;
      map<string, int> genresCntMap;
      multimap<string, pair<int, int>> playListData;

      for(int idx = 0; idx < genres.size(); idx++) {
          auto play_idx_pair = make_pair(plays[idx], idx);
          playListData.insert(make_pair(genres[idx] ,play_idx_pair));
          genresCntMap[genres[idx]] += plays[idx];
      }

      // map to vector and sort
      vector<pair<int, string>> genresCntVector;

      for(auto iter = genresCntMap.begin(); iter != genresCntMap.end(); iter++) {
          genresCntVector.push_back(make_pair(iter->second, iter->first));
      }
      sort(genresCntVector.rbegin(), genresCntVector.rend());

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
              if(cnt == 2)
                  break;
              answer.push_back(iter->second);
          }
      }
  ```