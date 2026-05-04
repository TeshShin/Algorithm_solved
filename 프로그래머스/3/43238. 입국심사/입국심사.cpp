#include <string>
#include <vector>

using namespace std;
using ll = long long;

bool Solve(ll mid, int n, const vector<int>& times)
{
    ll people = 0;
    for(int time : times)
    {
        people += (mid / time);
        if (people >= n)
        {
            return true;
        }
    }
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    ll left = 0;
    ll right = 1e18;
    
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(Solve(mid, n, times))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    
    return answer;
}