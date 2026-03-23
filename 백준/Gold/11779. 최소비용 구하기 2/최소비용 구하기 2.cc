#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

struct cmp {
	bool operator()(P a, P b) {
		return a.second > b.second;
	}
};

int N, M;
int from, to;

int Solve(const vector<vector<P>>& graph, vector<int>& distance, vector<int>& parent)
{
	distance[from] = 0;
	priority_queue<P, vector<P>, cmp> pq;

	pq.push({ from, 0 });
	while (!pq.empty())
	{
		P curr = pq.top();
		pq.pop();
		int currNode = curr.first;
		int currDist = curr.second;
		if (distance[currNode] < currDist) continue;
		
		for (P next : graph[currNode])
		{
			int nextNode = next.first;
			int newDist = next.second + distance[currNode];
			if (distance[nextNode] > newDist)
			{
				distance[nextNode] = newDist;
				parent[nextNode] = currNode;
				pq.push({ nextNode, newDist });
			}
		}
	}
	return distance[to];
}

void FindParent(vector<int>& parent)
{
	vector<int> path;
	int curr = to;
	path.push_back(curr);
	while (parent[curr])
	{
		path.push_back(parent[curr]);
		curr = parent[curr];
	}
	reverse(path.begin(), path.end());
	cout << path.size() << '\n';
	for (auto answer : path)
		cout << answer << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<vector<P>> graph(N + 1);
	const int inf = 100'000 * N;
	vector<int> distance(N + 1, inf);
	vector<int> parent(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}
	cin >> from >> to;
	cout << Solve(graph, distance, parent) << '\n';
	FindParent(parent);
	return 0;
}