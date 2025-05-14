#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 1. 각 학생의 위치에서 X까지의 최단거리를 구한다.
// 2. X에서부터 각 학생의 위치까지의 최단거리를 구한다.

#define MAX 200000
int N, M, X;

struct cmp
{
	bool operator()(pair<int,int> a, pair<int,int> b) 
	{
		return a.second > b.second;
	}
};

// 한 학생에서 X까지 최단 거리 & X에서 학생까지 최단 거리
int dijkstra(vector<vector<pair<int, int>>>& graph, int from, int to)
{
	// 한 From마다의 최단 거리 저장
	vector<int> distance(N + 1, MAX);
	priority_queue< pair<int, int>, vector<pair<int, int>>, cmp> pq;

	distance[from] = 0;
	pq.push(make_pair(from, 0));
	while (!pq.empty())
	{
		pair<int,int> curr = pq.top();
		pq.pop();
		
		if (curr.second < distance[curr.first]) continue;

		for (const pair<int, int> nextWay : graph[curr.first])
		{
			int nextName = nextWay.first;
			int newtime = distance[curr.first] + nextWay.second;
			if (distance[nextName] > newtime)
			{
				distance[nextName] = newtime;
				pq.push(make_pair(nextName, newtime));
			}
		}
	}
	return distance[to];
}
int party(vector<vector<pair<int, int>>>& graph)
{
	int longWay = 0;
	for (int i = 1; i <= N; i++)
	{
		int studentWay = dijkstra(graph, i, X) + dijkstra(graph, X, i);
		longWay = (longWay < studentWay) ? studentWay : longWay;
	}
	return longWay;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> X;
	// 도로 정보 저장
	vector<vector<pair<int, int>>> graph(N + 1);

	for (int i = 0; i < M; i++)
	{
		int from, to, timeCost;
		cin >> from >> to >> timeCost;
		graph[from].push_back(make_pair(to, timeCost));
	}

	cout << party(graph);

	return 0;
}