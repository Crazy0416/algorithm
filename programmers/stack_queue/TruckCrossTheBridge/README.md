# 프로그래머스 고득점 kit 스택/큐 다리를 지나는 트럭

## 문제점
- 생각을 너무 복잡하게 한다.
- 생각이 꼬여 간단한 구현을 오래걸렸다.
- 굳이 전부 큐를 돌면서 -1을 하였다.
    - 쓸모없는 계산이 늘었다.

## 다른 사람의 해결법
- 트럭이 큐에 추가될 때 현재 지난 시간의 총합과 다리의 길이를 더한다.
    - 마지막 데이터가 큐에서 pop 될때 그 값을 answer에 대입하면 끝.

```cpp
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int count = 0;              // iterator 역할
    int Time = 0;               // 시간
    int Truck_weight = 0;
    queue<pair<int, int>> truck_move;       // 다리위에 있는 트럭을 큐로 나타냄

    while (true)
    {
        // 다리위에 있는 트럭 무게 총량과 다음 트럭이 다리 위에 올라가도 괜찮다면
        if (weight >= Truck_weight + truck_weights.at(count))
        {
            // Time + 1을 추가적으로 더한다.
            truck_move.push(make_pair(truck_weights.at(count), **bridge_length + 1 + Time**));
            Truck_weight += truck_weights.at(count);    // 다리 위에 있는 트럭 무게의 총량
            count++;    // 다음 트럭 가르키기
        }

        if (count >= truck_weights.size())  // 모든 트럭이 다 지나갔다면
        {
            answer = truck_move.back().second;
            break;
        }
        else
        {
            Time++;
            if (truck_move.front().second == Time+1) // 트럭이 시간이 다 되어 다리를 다 지났다면
            {
                Truck_weight -= truck_move.front().first;
                truck_move.pop();
            }
        }

    }

    return answer;
}
```
