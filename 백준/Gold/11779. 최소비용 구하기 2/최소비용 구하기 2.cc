#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

int N, M;

struct cmp {
	bool operator()(const P& a, const P& b) const {
		return a.second > b.second;
	}
};

int Solve(const vector<vector<P>>& graph, vector<int>& distance, vector<int>& parent, int start, int end)
{
	distance[start] = 0;
	priority_queue<P, vector<P>, cmp> pq;

	pq.push({ start, 0 });
	while (!pq.empty())
	{
		P curr = pq.top();
		pq.pop();
		int currNode = curr.first;
		int currDist = curr.second;
		if (distance[currNode] < currDist) continue;
		
		for (const P& next : graph[currNode])
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
	return distance[end];
}

void PrintPath(const vector<int>& parent, int end)
{
	vector<int> path;
	int curr = end;
	path.push_back(curr);
	while (parent[curr])
	{
		path.push_back(parent[curr]);
		curr = parent[curr];
	}
	reverse(path.begin(), path.end());
	cout << path.size() << '\n';
	for (int node : path)
		cout << node << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<vector<P>> graph(N + 1);
	const int inf = 1e9;
	vector<int> distance(N + 1, inf);
	vector<int> parent(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}

	int start, end;
	cin >> start >> end;
	cout << Solve(graph, distance, parent, start, end) << '\n';
	PrintPath(parent, end);
	return 0;
}