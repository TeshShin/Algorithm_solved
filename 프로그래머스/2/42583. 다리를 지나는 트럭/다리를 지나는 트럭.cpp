#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> wait;
    queue<int> bridge;
    
    for (int i = 0; i < truck_weights.size(); i++) {
        wait.push(truck_weights[i]);
    }
    int totalweight = 0;
    while (!wait.empty()) {
        answer++;

        if (bridge.size() == bridge_length) {
            totalweight -= bridge.front();
            bridge.pop();
        }
        
        if (!wait.empty() && totalweight + wait.front() <= weight) {
            totalweight += wait.front();
            bridge.push(wait.front());
            wait.pop();
        }

        else {
            bridge.push(0);
        }
        
    }
    answer += bridge_length;


    return answer;


}