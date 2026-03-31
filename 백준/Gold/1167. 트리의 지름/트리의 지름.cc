#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <stack>
using namespace std;
using P = pair<int, int>;
int V;

int FindFarthestNode(const vector<vector<P>>& graph, int start, int& maxNode)
{
	int maxCost = 0;
	stack<int> st;
	vector<int> dist(V + 1, -1);
	st.push(start);
	dist[start] = 0;
	maxNode = start;
	while (!st.empty())
	{
		int curr = st.top();
		st.pop();

		for (const P& next : graph[curr])
		{
			if (dist[next.first] != -1) continue;
			st.push(next.first);
			dist[next.first] = dist[curr] + next.second;
			if (maxCost < dist[next.first])
			{
				maxCost = dist[next.first];
				maxNode = next.first;
			}
		}
	}
	return maxCost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V;
	vector<vector<P>> graph(V + 1);
	for (int i = 1; i <= V; i++)
	{
		int from;
		cin >> from;
		while (true)
		{
			int to;
			cin >> to;
			if (to == -1) break;
			int cost;
			cin >> cost;
			graph[from].push_back({ to, cost });
		}
	}

	int maxNode = 1;
	FindFarthestNode(graph, 1, maxNode);
	int maxDist = FindFarthestNode(graph, maxNode, maxNode);
	cout << maxDist;
	return 0;
}