#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int Root[100001];

void Init(int vCount) {
	for (int i = 1; i <= vCount; i++)
	{
		Root[i] = i;
	}
}

int Find(int x)
{
	if (Root[x] == x) return x;
	Root[x] = Find(Root[x]);
	return Root[x];
}

bool Union(int a, int b)
{
	int aRoot = Find(a);
	int bRoot = Find(b);
	if (aRoot == bRoot) return false;
	if (aRoot < bRoot)
	{
		Root[bRoot] = aRoot;
	}
	else
	{
		Root[aRoot] = bRoot;
	}
	return true;
}

struct FEdge
{
	int from, to, cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;

	vector<FEdge> edges;
	cin >> N >> M;

	Init(N);
	int from, to, cost;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		edges.push_back({ from, to, cost });
	}
	sort(edges.begin(), edges.end(),
		[](const FEdge& a, const FEdge& b)
		{
			return a.cost < b.cost;
		});


	int minCost = 0;
	int Times = 0;
	for (const FEdge& edge : edges)
	{
		if (Times == N - 2)
		{
			break;
		}
		if (Union(edge.from, edge.to))
		{
			minCost += edge.cost;
			Times++;
		}
	}
	cout << minCost;

	return 0;
}