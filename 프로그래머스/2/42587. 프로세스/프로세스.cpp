#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> wait;
    int tries = 0;
    for (int i = 0; i < priorities.size(); i++) {
        wait.push(priorities[i]);
    }
    while (true) {
        bool active = true;
        int save = wait.front();
        wait.pop();
        for (int i = 0; i < wait.size(); i++) {
            if (wait.front() > save) {
                active = false;
            }
            wait.push(wait.front());
            wait.pop();
        }
        if (active) {
            answer++;
            if (tries == location) return answer;
        }
        else {
            wait.push(save);
            if (tries == location) location += wait.size();
        }
        tries++;
    }
    

    
}