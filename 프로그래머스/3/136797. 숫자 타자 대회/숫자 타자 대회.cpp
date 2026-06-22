#include <string>
#include <vector>

using namespace std;
using vvi = vector<vector<int>>;
using vvvi = vector<vvi>;
constexpr int INF = 700'001;
int calcCost(int from, int to, const vector<pair<int, int>>& pos)
{
    if(from == to)
    {
        return 1;
    }
    else
    {
        int diffCol = abs(pos[from].second - pos[to].second);
        int diffRow = abs(pos[from].first - pos[to].first);
        int result = min(diffCol, diffRow) * 3 
            + (max(diffCol, diffRow) - min(diffCol, diffRow)) * 2;
        return result;
    }
}

int solution(string numbers) {
    int answer = INF;
    vector<pair<int, int>> pos(10);
    for(int i = 0; i < 10; i++)
    {
        if(i == 0)
        {
            pos[i] = {3, 1};
        }
        else
        {
            pos[i] = {(i - 1) / 3, (i - 1) % 3};
        }
    }
    vvi cost(10, vector<int>(10));
    for(int i = 0; i < 10; i++)
    {
        for(int j = i; j < 10; j++)
        {
            cost[i][j] = calcCost(i, j, pos);
            cost[j][i] = cost[i][j];
        }
    }
    
    int n = numbers.length();
    vvvi dp (n + 1, vector<vector<int>> (10, vector<int> (10, INF)));
    dp[0][4][6] = 0;
    for(int i = 0; i < n; i++)
    {
        int num = numbers[i] - '0';
        // 해당 인덱스를 왼손, 오른손 각각으로
        for(int l = 0; l <= 9; l++)
        {
            for(int r = 0; r <= 9; r++)
            {
                if(dp[i][l][r] == INF) continue;
                if(num == l || num == r) // l과 r이 같아지는 상황을 제외
                {
                    dp[i + 1][l][r] = min(dp[i + 1][l][r], dp[i][l][r] + 1);
                }
                else
                {
                    dp[i + 1][num][r] = min(dp[i + 1][num][r], dp[i][l][r] + cost[l][num]);
                    dp[i + 1][l][num] = min(dp[i + 1][l][num], dp[i][l][r] + cost[r][num]);
                }
            }
        }
    }
    for(int l = 0; l <= 9; l++)
    {
        for(int r = 0; r <= 9; r++)
        {
            if(dp[n][l][r] < answer)
            {
                answer = dp[n][l][r];
            }
        }
    }
    return answer;
}