#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using vvi = vector<vector<int>>;

constexpr int INF = 1'000'000'000;

int CalcCost(int from, int to, const vector<pair<int, int>>& positions)
{
    if (from == to)
    {
        return 1;
    }

    int rowDiff = abs(positions[from].first - positions[to].first);
    int colDiff = abs(positions[from].second - positions[to].second);

    int diagonal = min(rowDiff, colDiff);
    int straight = max(rowDiff, colDiff) - diagonal;

    return diagonal * 3 + straight * 2;
}

vector<pair<int, int>> MakePositions()
{
    vector<pair<int, int>> positions(10);

    for (int number = 1; number <= 9; ++number)
    {
        positions[number] = {(number - 1) / 3, (number - 1) % 3};
    }

    positions[0] = {3, 1};

    return positions;
}

vvi MakeCostTable(const vector<pair<int, int>>& positions)
{
    vvi cost(10, vector<int>(10, 0));

    for (int from = 0; from <= 9; ++from)
    {
        for (int to = 0; to <= 9; ++to)
        {
            cost[from][to] = CalcCost(from, to, positions);
        }
    }

    return cost;
}

int solution(string numbers)
{
    int answer = INF;

    vector<pair<int, int>> positions = MakePositions();
    vvi cost = MakeCostTable(positions);

    vvi currentDp(10, vector<int>(10, INF));
    vvi nextDp(10, vector<int>(10, INF));

    currentDp[4][6] = 0;

    for (char digit : numbers)
    {
        int number = digit - '0';

        for (int left = 0; left <= 9; ++left)
        {
            fill(nextDp[left].begin(), nextDp[left].end(), INF);
        }

        for (int left = 0; left <= 9; ++left)
        {
            for (int right = 0; right <= 9; ++right)
            {
                if (currentDp[left][right] == INF)
                {
                    continue;
                }

                if (number == left || number == right)
                {
                    nextDp[left][right] = min(
                        nextDp[left][right],
                        currentDp[left][right] + 1
                    );
                }
                else
                {
                    nextDp[number][right] = min(
                        nextDp[number][right],
                        currentDp[left][right] + cost[left][number]
                    );

                    nextDp[left][number] = min(
                        nextDp[left][number],
                        currentDp[left][right] + cost[right][number]
                    );
                }
            }
        }

        currentDp = nextDp;
    }

    for (int left = 0; left <= 9; ++left)
    {
        for (int right = 0; right <= 9; ++right)
        {
            answer = min(answer, currentDp[left][right]);
        }
    }

    return answer;
}