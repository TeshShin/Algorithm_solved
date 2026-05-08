#include <string>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<ll> pq;
    for(int work : works)
    {
        pq.push((ll)work);
    }
    
    for(int i = 0; i < n; i++)
    {
        ll maxWork = pq.top();
        if(maxWork == 0)
        {
            break;
        }
        pq.pop();
        pq.push(maxWork - 1);
    }
    while(!pq.empty())
    {
        ll leftWork = pq.top();
        pq.pop();
        answer += leftWork * leftWork;
    }
    return answer;
}