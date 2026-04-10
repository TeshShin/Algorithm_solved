#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int Parent[10001];

void Init(int vertexCount)
{
	for (int vertex = 1; vertex <= vertexCount; vertex++)
	{
		Parent[vertex] = vertex;
	}
}

int Find(int vertex)
{
	if (Parent[vertex] == vertex) return vertex;
	Parent[vertex] = Find(Parent[vertex]);
	return Parent[vertex];
}

bool Union(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB) return false;

	if (rootA < rootB)
	{
		Parent[rootB] = rootA;
	}
	else
	{
		Parent[rootA] = rootB;
	}
	return true;
}

struct FEdge
{
	int From;
	int To;
	int Cost;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int V, E;
	cin >> V >> E;
	Init(V);
	vector<FEdge> Edges;
	int from, to, cost;
	for (int i = 0; i < E; i++)
	{
		cin >> from >> to >> cost;
		Edges.push_back({ from, to, cost });
	}
	sort(Edges.begin(), Edges.end(), 
		[](const FEdge& a, const FEdge& b)
		{
			return a.Cost < b.Cost;
		});
	int minCost = 0;
	int lines = 0;
	for (const FEdge& Edge : Edges)
	{
		if (Union(Edge.From, Edge.To))
		{
			minCost += Edge.Cost;
			lines++;
		}
		if (lines == V - 1)
		{
			break;
		}
	}
	cout << minCost;


	return 0;
}