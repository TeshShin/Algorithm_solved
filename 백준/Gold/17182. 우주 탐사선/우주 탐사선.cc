#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int inf = 1e9;
using V2 = vector<vector<int>>;

int N, K;
int answer = inf;
void Floyd(V2& graph)
{
	for (int mid = 0; mid < N; mid++)
	{
		for (int from = 0; from < N; from++)
		{
			for (int to = 0; to < N; to++)
			{
				graph[from][to] = min(graph[from][to], graph[from][mid] + graph[mid][to]);
			}
		}
	}
}
void Dfs(const V2& graph, int current, int visited, int cost)
{
	if (visited == (1 << N) - 1)
	{
		answer = min(answer, cost);
		return;
	}
	if (cost >= answer)
	{
		return;
	}
	for (int next = 0; next < N; next++)
	{
		if (visited & (1 << next))
			continue;
		Dfs(graph, next, visited | (1 << next), cost + graph[current][next]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	V2 graph(N, vector<int>(N, inf));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}
	Floyd(graph);
	Dfs(graph, K, 1 << K, 0);
	cout << answer;
	return 0;
}