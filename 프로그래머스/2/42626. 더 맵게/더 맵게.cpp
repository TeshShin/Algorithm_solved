#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    for(int n : scoville)
    {
        pq.push(n);
    }
    while(true)
    {
        if(pq.top() >= K)
        {
            return answer;
        }
        else if(pq.size() == 1)
        {
            return -1;
        }
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }

    return answer;
}