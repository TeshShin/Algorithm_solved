#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vvpii graph(n + 1);
    vector<int> dist(n + 1, 10'000'001);
    vector<bool> isSummit(n + 1);
    for(const vector<int>& path : paths)
    {
        graph[path[0]].push_back({path[2], path[1]});
        graph[path[1]].push_back({path[2], path[0]});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int gate : gates)
    {
        pq.push({0, gate});
        dist[gate] = 0;
    }
    for(int summit : summits)
    {
        isSummit[summit] = true;
    }
    while(!pq.empty())
    {
        int intensity = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(intensity > dist[node] || isSummit[node]) continue;
        
        for(const pii& curr : graph[node])
        {
            int nextIntensity = max(intensity, curr.first);
            int nextNode = curr.second;
            if(dist[nextNode] == 0) continue;
            if(dist[nextNode] > nextIntensity)
            {
                dist[nextNode] = nextIntensity;
                pq.push({nextIntensity, nextNode});
            }
        }
    }
    sort(summits.begin(), summits.end());
    int minSummit;
    int minIntensity = 10'000'001;
    for(int summit : summits)
    {
        if (dist[summit] < minIntensity)
        {
            minSummit = summit;
            minIntensity = dist[summit];
        }
    }
    answer.push_back(minSummit);
    answer.push_back(minIntensity);
    return answer;
}