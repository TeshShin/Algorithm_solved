#include <string>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vll = vector<ll>;

long long solution(vector<int> a, vector<vector<int>> edges) {
    const int nodeCount = a.size();
    vii graph(nodeCount);
    vll value(nodeCount);
    ll totalSum = 0;
    for(int i = 0; i < nodeCount; i++)
    {
        value[i] = a[i];
        totalSum += value[i];
    }
    if(totalSum != 0)
    {
        return -1;
    }
    
    for(const vi& edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    long long answer = 0;
    vi order;
    vll parent(nodeCount, -1);
    order.reserve(nodeCount);
    stack<int> nodeStack;
    parent[0] = 0;
    nodeStack.push(0);
    
    while(!nodeStack.empty())
    {
        int current = nodeStack.top();
        nodeStack.pop();
        
        order.push_back(current);
        for(int next : graph[current])
        {
            if(parent[next] != -1)
            {
                continue;
            }
            
            parent[next] = current;
            nodeStack.push(next);
        }
    }
    
    for(int i = nodeCount - 1; i > 0; i--)
    {
        int current = order[i];
        int parentNode = parent[current];
        
        value[parentNode] += value[current];
        answer += abs(value[current]);
    }
    
    
    return answer;
}