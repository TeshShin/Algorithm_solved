#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
enum EDir
{
    Left,
    Right,
    Up,
    Down
};
void Clamp (ll& minNum, ll& maxNum, ll limit)
{
    minNum = max(minNum, 0LL);
    maxNum = min(maxNum, limit - 1);
}
void RMoving(EDir dir, ll dx, ll& minRow, ll& maxRow, ll& minCol, ll& maxCol, ll n, ll m)
{
    switch(dir)
    {
        case Left:
            if(minCol != 0)
            {
                minCol += dx;
            }
            maxCol += dx;
            Clamp(minCol, maxCol, m);
            break;
        case Right:
            if(maxCol != m - 1)
            {
                maxCol -= dx;
            }
            minCol -= dx;
            Clamp(minCol, maxCol, m);
            break;
        case Up:
            if(minRow != 0)
            {
                minRow += dx;
            }
            maxRow += dx;
            Clamp(minRow, maxRow, n);
            break;
        case Down:
            if(maxRow != n - 1)
            {
                maxRow -= dx;
            }
            minRow -= dx;
            Clamp(minRow, maxRow, n);
            break;
    }
}
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    ll minRow = x;
    ll maxRow = x;
    ll minCol = y;
    ll maxCol = y;
    for(int i = queries.size() - 1; i >= 0; i--)
    {
        const vector<int>& query = queries[i];
        EDir dir = static_cast<EDir>(query[0]);
        int dx = query[1];
        RMoving(dir,dx,minRow,maxRow,minCol,maxCol,n,m);
        if(minRow > maxRow || minCol > maxCol)
        {
            return 0;
        }
    }
    answer = (maxRow - minRow + 1) * (maxCol - minCol + 1);
    return answer;
}