#include<iostream>
#include<vector>
using namespace std;
#define MAX 5'000'000
int TC, N, M, W;

void BellmanFord(vector<vector<pair<int, int>>>& graph, int start)
{
	vector<int> distance(N + 1, MAX);
	distance[start] = 0;
	//  n-1 반복 -> N번째 확인에도 갱신된다면 음수 사이클 존재
	for (int i = 1; i < N; i++)
	{
		// 매 반복마다 '모든 간선'을 하나씩 확인한다.
		for (int j = 1; j <= N; j++)
		{
			for (pair<int, int> edge : graph[j])
			{
				int from = j;
				int to = edge.first;
				int cost = edge.second;
				// 원래는 한번이라도 계산된 정점에 대해서만 update(단절된 정점은 제외)
				// if (distance[from] == MAX) continue;
				// 하지만 우리는 시작점이 정해져 있지않고,
				// 음수 사이클을 찾아야하므로
				// 단절된 노드에도 사이클이 존재하는지 확인해야한다.
				// 따라서 해당 조건을 생략한다.
				// 
				// 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
				if (distance[to] > distance[from] + cost)
				{
					distance[to] = distance[from] + cost;
				}
			}
		}
	}
	// n번째 확인
	for (int j = 1; j <= N; j++)
	{
		for (pair<int, int> edge : graph[j])
		{
			int from = j;
			int to = edge.first;
			int cost = edge.second;
			// 한번이라도 계산된 정점에 대해서만 update(단절된 정점은 제외)
			// if (distance[from] == MAX) continue;
			// 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if (distance[to] > distance[from] + cost)
			{
				cout << "YES" << '\n';
				return;
			}
		}
	}
	cout << "NO" << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> TC;
	while (TC--)
	{
		cin >> N >> M >> W;
		vector<vector<pair<int,int>>> graph(N + 1);
		while (M--)
		{
			int S, E, T;
			cin >> S >> E >> T;
			graph[S].push_back(make_pair(E, T));
			graph[E].push_back(make_pair(S, T));
		}
		while (W--)
		{
			int S, E, T;
			cin >> S >> E >> T;
			graph[S].push_back(make_pair(E, -T));
		}
		BellmanFord(graph, 1);
	}


	return 0;
}