#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> win(n + 1, vector<bool>(n + 1));
    for(const vector<int>& round : results)
    {
        int winner = round[0];
        int loser = round[1];
        win[winner][loser] = true;
    }
    for(int mid = 1; mid <= n; mid++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(win[i][mid] && win[mid][j])
                {
                   win[i][j] = true;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        bool known = true;
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            if(!(win[i][j] || win[j][i]))
            {
                known = false;
                break;   
            }
        }
        if(known) 
        {
            answer++;
        }
    }
    return answer;
}