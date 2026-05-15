#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Drop(const vector<vector<int>>& children, vector<int>& childrenIndex)
{
    int node = 1;

    while (!children[node].empty())
    {
        int index = childrenIndex[node];
        childrenIndex[node] = (index + 1) % children[node].size();
        node = children[node][index];
    }

    return node;
}

bool CanMakeTarget(const vector<int>& target, const vector<int>& leafCount)
{
    int nodeCount = target.size();

    for (int node = 1; node <= nodeCount; node++)
    {
        int count = leafCount[node];
        int value = target[node - 1];

        if (value < count || value > count * 3)
        {
            return false;
        }
    }

    return true;
}

vector<int> BuildAnswer(
    const vector<int>& target,
    const vector<int>& leafCount,
    const vector<int>& arriveNodes)
{
    int nodeCount = target.size();

    vector<vector<int>> nodeValues(nodeCount + 1);
    vector<int> pushIndex(nodeCount + 1, 0);
    vector<int> result;

    for (int node = 1; node <= nodeCount; node++)
    {
        int count = leafCount[node];
        int value = target[node - 1];

        nodeValues[node] = vector<int>(count, 1);

        int left = value - count;

        for (int index = count - 1; index >= 0 && left > 0; index--)
        {
            int add = min(2, left);
            nodeValues[node][index] += add;
            left -= add;
        }
    }

    for (int node : arriveNodes)
    {
        int index = pushIndex[node]++;
        result.push_back(nodeValues[node][index]);
    }

    return result;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target)
{
    int nodeCount = target.size();

    vector<vector<int>> children(nodeCount + 1);
    vector<int> childrenIndex(nodeCount + 1, 0);
    vector<int> leafCount(nodeCount + 1, 0);
    vector<int> arriveNodes;

    for (const vector<int>& edge : edges)
    {
        int parent = edge[0];
        int child = edge[1];

        children[parent].push_back(child);
    }

    for (int node = 1; node <= nodeCount; node++)
    {
        sort(children[node].begin(), children[node].end());
    }

    while (true)
    {
        int leaf = Drop(children, childrenIndex);

        leafCount[leaf]++;
        arriveNodes.push_back(leaf);

        if (leafCount[leaf] > target[leaf - 1])
        {
            return {-1};
        }

        if (CanMakeTarget(target, leafCount))
        {
            break;
        }
    }

    return BuildAnswer(target, leafCount, arriveNodes);
}