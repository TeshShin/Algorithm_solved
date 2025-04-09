#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 200000

int V, E, K;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};
void shortWay(vector<vector<pair<int, int>>>& graph, vector<int>& distance, int K)
{
	distance[K] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ K, 0 });

	while (!pq.empty())
	{
		pair<int, int> curr = pq.top();
		pq.pop();

		if (curr.second > distance[curr.first]) continue;

		for (const pair<int, int> e : graph[curr.first])
		{
			int v = e.first;
			int newdist = distance[curr.first] + e.second;
			if (distance[v] > newdist)
			{
				distance[v] = newdist;
				pq.push({ v, newdist });
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;
	vector<vector<pair<int,int>>> graph(V + 1);
	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
	}
	vector<int> distance(V + 1, MAX);
	shortWay(graph, distance, K);

	for (int i = 1; i <= V; i++)
	{
		(distance[i] == MAX) ? cout << "INF" : cout << distance[i];
		cout << '\n';
	}
	return 0;
}