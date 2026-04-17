#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    vector<vector<int>> Wins(n + 1);
    vector<vector<int>> Loses(n + 1);

    for (const vector<int>& Result : results)
    {
        int Winner = Result[0];
        int Loser = Result[1];

        Wins[Winner].push_back(Loser);
        Loses[Loser].push_back(Winner);
    }

    int Answer = 0;

    for (int Player = 1; Player <= n; Player++)
    {
        int WinCount = 0;
        int LoseCount = 0;

        {
            vector<bool> Visited(n + 1, false);
            queue<int> Queue;

            Queue.push(Player);
            Visited[Player] = true;

            while (!Queue.empty())
            {
                int Current = Queue.front();
                Queue.pop();

                for (int Next : Wins[Current])
                {
                    if (Visited[Next])
                    {
                        continue;
                    }

                    Visited[Next] = true;
                    Queue.push(Next);
                    WinCount++;
                }
            }
        }

        {
            vector<bool> Visited(n + 1, false);
            queue<int> Queue;

            Queue.push(Player);
            Visited[Player] = true;

            while (!Queue.empty())
            {
                int Current = Queue.front();
                Queue.pop();

                for (int Next : Loses[Current])
                {
                    if (Visited[Next])
                    {
                        continue;
                    }

                    Visited[Next] = true;
                    Queue.push(Next);
                    LoseCount++;
                }
            }
        }

        if (WinCount + LoseCount == n - 1)
        {
            Answer++;
        }
    }

    return Answer;
}