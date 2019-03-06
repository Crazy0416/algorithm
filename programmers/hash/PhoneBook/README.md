# 프로그래머스 고득점 kit 해시 전화번호 목록
## 해결 아이디어
-

## 처음 해결법(오래 걸림)
- ```
  bool solution(vector<string> phone_book) {
      bool answer = true;
      map<string, vector<string>> list;

      for(int idx = 0; idx < phone_book.size(); idx++) {
          string phone_number = phone_book[idx];

          for(int pIdx = 1; pIdx <= phone_number.size(); pIdx++) {
              string number_split = phone_number.substr(0, pIdx);
              if(list.count(number_split) == 0) {
                  vector<string> dump;
                  pair<string, vector<string>> phone_map(number_split, dump);
                  phone_map.second.push_back(phone_number);
                  list.insert(phone_map);
              } else {
                  auto dump = list.find(number_split);
                  dump->second.push_back(phone_number);
              }
          }
      }

      for(int idx = 0; idx < phone_book.size(); idx++) {
          string phone_number = phone_book[idx];
          if(list.count(phone_number) != 0) {
              vector<string>& dump = list.find(phone_number)->second;
              for(int i = 0; i < dump.size(); i++) {
                  if(dump[i] != phone_number) {
                      answer = false;
                  }
              }
          }
      }

      return answer;
  }
  ```
- 너무 오래걸렸다. (효율성에서 점수 10점 깎임)


## 다른 해결 방법
- ```
  bool solution(vector<string> phone_book) {
      bool answer = true;
      map<string, int> list;

      for(int idx = 0; idx < phone_book.size(); idx++) {
          string phone_number = phone_book[idx];

          for(int pIdx = 1; pIdx <= phone_number.size(); pIdx++) {
              string number_split = phone_number.substr(0, pIdx);
              if(list.count(number_split) == 0) {
                  pair<string, int> phone_map(number_split, 1);
                  list.insert(phone_map);
              } else {
                  auto dump = list.find(number_split);
                  dump->second += 1;
              }
          }
      }

      for(int idx = 0; idx < phone_book.size(); idx++) {
          if(list.find(phone_book[idx])->second > 1) {
              answer = false;
              break;
          }
      }

      return answer;
  }
  ```