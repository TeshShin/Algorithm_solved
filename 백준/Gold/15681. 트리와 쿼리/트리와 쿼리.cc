#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, R, Q;



void countSubtreeNodes(const vector<vector<int>>& graph, vector<int>& subtreeSize, int current, int parent)
{
	subtreeSize[current] = 1;
	for (int node : graph[current])
	{
		if (node == parent) continue;
		countSubtreeNodes(graph, subtreeSize, node, current);
		subtreeSize[current] += subtreeSize[node];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> R >> Q;
	vector<vector<int>> graph(N + 1);
	vector<int> subtreeSize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	countSubtreeNodes(graph, subtreeSize, R, R);
	for (int i = 0; i < Q; i++)
	{
		int query;
		cin >> query;
		cout << subtreeSize[query] << '\n';
	}

	return 0;
}