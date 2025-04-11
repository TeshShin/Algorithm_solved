#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 1600000

struct cmp
{
	bool operator()(pair<int, int>a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int N, E;
vector<pair<int, int>> graph[801];
int shortWay(int s, int e)
{
	vector<int> distance(N + 1, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	distance[s] = 0;
	pq.push({ s, 0 });
	while (!pq.empty())
	{
		pair<int, int> curr = pq.top();
		pq.pop();
		if (curr.second > distance[curr.first]) continue;
		for (const pair<int, int> next : graph[curr.first])
		{
			int v = next.first;
			int newcost = distance[curr.first] + next.second;
			if (distance[v] > newcost)
			{
				distance[v] = newcost;
				pq.push({ v, newcost });
			}
		}
	}
	return distance[e];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({ end, cost });
		graph[end].push_back({ start, cost });
	}

	int a, b;
	cin >> a >> b;

	int aFirst = shortWay(1, a) + shortWay(a, b) + shortWay(b, N);
	int bFirst = shortWay(1, b) + shortWay(b, a) + shortWay(a, N);

	if (aFirst >= MAX && bFirst >= MAX) cout << -1;
	else cout << min(aFirst, bFirst);

	return 0;
}