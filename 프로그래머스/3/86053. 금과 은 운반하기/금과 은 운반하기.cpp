#include <string>
#include <vector>

using namespace std;
using ll = long long;


long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll Left = 0;
    ll Right = 2e9 * 2 * 1e5;
    ll answer = Right;
    
    while(Left <= Right)
    {
        ll Mid = (Left + Right) / 2;
        
        ll Gold = 0;
        ll Silver = 0;
        ll Total = 0;
        for(int i = 0; i < g.size(); i++)
        {
            ll MoveCount = Mid / (2 * t[i]);
            
            if(Mid % (2 * t[i]) >= t[i])
            {
                MoveCount++;
            }
            ll MaxWeight = MoveCount * w[i];
            Gold += min((ll)g[i], MaxWeight);
            Silver += min((ll)s[i], MaxWeight);
            Total += min((ll)g[i] + s[i], MaxWeight);
        }
        
        if(Total >= a + b && Gold >= a && Silver >= b)
        {
            answer = Mid;
            Right = Mid - 1;
        }
        else
        {
            Left = Mid + 1;
        }
    }
    
    
    return answer;
}