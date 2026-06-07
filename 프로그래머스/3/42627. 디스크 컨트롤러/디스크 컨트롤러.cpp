#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(const vector<int>& job : jobs)
    {
        pq.push(job);
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pJob;
    vector<int> turnTime;
    int time = 0;
    while(turnTime.size() < jobs.size())
    {
        while(!pq.empty() && pq.top()[0] <= time)
        {
            vector<int> job = pq.top();
            pJob.push({job[1], job[0]});
            pq.pop();
        }
        if(pJob.empty())
        {
            time++;
            continue;
        }
        vector<int> job = pJob.top();
        int workingTime = job[0];
        int requireTime = job[1];
        pJob.pop();
        turnTime.push_back(time + workingTime - requireTime);
        time += workingTime;
    }
    for(int t : turnTime)
    {
        answer += t;
    }
    return answer / jobs.size();
}