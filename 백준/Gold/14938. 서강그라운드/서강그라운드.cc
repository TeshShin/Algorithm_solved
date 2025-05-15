#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1'500
int n, m, r;
struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start)
{
	vector<int> distance(n + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	vector<int> canGoList;
	distance[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		pair<int, int> curr = pq.top();
		pq.pop();
		for (pair<int, int> next : graph[curr.first])
		{
			int nextName = next.first;
			int newCost = distance[curr.first] + next.second;
			if (distance[nextName] > newCost)
			{
				distance[nextName] = newCost;
				pq.push({ nextName, newCost });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (distance[i] <= m)
		{
			canGoList.push_back(i);
		}
	}
	return canGoList;
}
int MaxItem(vector<vector<pair<int, int>>>& graph, vector<int>& items)
{
	int maxitem = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<int> canGoList = dijkstra(graph, i);
		int itemcount = 0;
		for (int node : canGoList)
		{
			itemcount += items[node];
		}
		maxitem = maxitem > itemcount ? maxitem : itemcount;
	}
	return maxitem;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r;
	vector<vector<pair<int,int>>> graph(n + 1);
	vector<int> items(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> items[i];
	}
	for (int i = 0; i < r; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}
	cout << MaxItem(graph, items);

	return 0;
}