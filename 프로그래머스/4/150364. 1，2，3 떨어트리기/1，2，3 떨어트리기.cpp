#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(const vector<int>& target, const vector<int>& leafCount)
{
    for(int i = 1; i <= target.size(); i++)
    {
        if(leafCount[i] <= target[i - 1] && target[i - 1] <= leafCount[i] * 3)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}


vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    // 노드는 1부터니까
    vector<vector<int>> children(target.size() + 1);
    vector<int> childrenIndex(target.size() + 1, 0);
    vector<int> leafCount(target.size() + 1, 0);
    vector<int> arriveIdx;
    for(auto& edge : edges)
    {
        int parent = edge[0];
        int child = edge[1];
        children[parent].push_back(child);
    }
    for(int i = 1; i < target.size() + 1; i++)
    {
        sort(children[i].begin(), children[i].end());
    }
    while(true)
    {
        int Idx = 1;
        while(children[Idx].size() > 0)
        {
            // 자식으로 내려가기
            int childIdx = childrenIndex[Idx];
            // 내려가기 전 현재 노드의 간선 바꾸기
            childrenIndex[Idx] = (childIdx + 1) % children[Idx].size();
            Idx = children[Idx][childIdx];
        }
        // 현재 Idx 는 리프임
        leafCount[Idx]++;
        arriveIdx.push_back(Idx);
        if(leafCount[Idx] > target[Idx - 1])
        {
            // 초과해서 ㅈㅈ
            return {-1};
        }
        else if(leafCount[Idx] <= target[Idx - 1] && target[Idx - 1] <= leafCount[Idx] * 3)
        {
            if(Check(target, leafCount))
            {
                // 이땐 걍 되는 거임.
                break;
            }
        }
    }
    vector<vector<int>> nodePush(target.size() + 1);
    for(int i = 1; i <= target.size(); i++)
    {
        int value = target[i - 1];
        int visitedCount = leafCount[i];
        for(int j = 1; j <= visitedCount; j++)
        {
            nodePush[i].push_back(1);
        }
        int left = value - visitedCount;
        
        int curr = 0;
        while(left > 0 && curr < visitedCount)
        {
            if(left >= 2)
            {
                nodePush[i][curr] = 3;
                left -= 2;
            }
            else if(left == 1)
            {
                nodePush[i][curr] = 2;
                left -= 1;
            }
            curr++;
        }
        reverse(nodePush[i].begin(), nodePush[i].end());
    }
    vector<int> pushIdx(target.size() + 1, 0);
    for(int i = 0; i < arriveIdx.size(); i++)
    {
        int currentNode = arriveIdx[i];
        int Idx = pushIdx[currentNode];
        answer.push_back(nodePush[currentNode][Idx]);
        pushIdx[currentNode]++;
    }
    return answer;
}