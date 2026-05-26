#include <string>
#include <vector>
#include <queue>
using namespace std;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
using vvpi = vector<vector<pii>>;
#define MAX 20'000'000

// 다익스트라
int Shortest(const vvpi& graph, int n, int from, int s, int a, int b)
{
    vector<int> distance(n + 1, MAX);
    distance[from] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, from});
    while(!pq.empty())
    {
        pii current = pq.top();
        pq.pop();
        int cost = current.first;
        int curr = current.second;
        
        if(cost > distance[curr]) continue;
        
        for(const pii node : graph[curr])
        {
            int newCost = node.first + cost;
            int nextNode = node.second;
            if(distance[nextNode] > newCost)
            {
                distance[nextNode] = newCost;
                pq.push({newCost, nextNode});
            }
        }
    }
    return distance[s] + distance[a] + distance[b];
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX;
    vvpi graph(n + 1);
    // {코스트, 목적지} 순으로
    for(const vector<int>& node : fares)
    {
        int from = node[0];
        int to = node[1];
        int cost = node[2];
        graph[from].push_back({cost, to});
        graph[to].push_back({cost, from});
    }
    for(int i = 1; i <= n; i++)
    {
        answer = min(answer, Shortest(graph, n, i, s, a, b));
    }
    
    
    return answer;
}