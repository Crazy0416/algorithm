#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int truck_sum(deque<int>& bridge) {
    int sum = 0;
    for(auto iter = bridge.begin(); iter != bridge.end(); iter++)
        sum += *iter;

    return sum;
}

bool truck_pass(deque<int>& truck_dist) {
    for(auto iter = truck_dist.begin(); iter != truck_dist.end(); iter++)
        *iter -= 1;

    return *truck_dist.begin() == 0;
}
//
//void showBridge(const deque<int>& bridge) {
//    for(auto iter = bridge.begin(); iter != bridge.end(); iter++)
//        cout << *iter << " ";
//    cout << endl;
//}
//
//void showData(int time, deque<int>& bridge, deque<int>& truck_dist) {
//    cout << "time: " << time << endl
//         << "bridge: ";
//    showBridge(bridge);
//    cout << "dist: ";
//    showBridge(truck_dist);
//    cout << endl;
//}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    deque<int> bridge;
    deque<int> truck_dist;
    auto iter = truck_weights.begin();

    while(true) {
        time++;

        if(iter != truck_weights.end()) {
            int bridgeWeight = truck_sum(bridge);
            bridgeWeight += *iter;

            if(bridgeWeight <= weight) {
                bridge.push_back(*iter);
                truck_dist.push_back(bridge_length);
                iter++;
            }
        }

        //showData(time, bridge, truck_dist);

        if(truck_pass(truck_dist)) {
            bridge.pop_front();
            truck_dist.pop_front();

            if(iter == truck_weights.end() && truck_dist.size() == 0) {
                time++;
                break;
            }
        }
    }

    return time;
}

int main() {
    vector<int> truck_weights = {10};

    cout << solution(100, 100, truck_weights) << endl;
    return 0;
}