#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;

// 이건 sort함수에만 가능
bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

// 우선 순위 큐는 구조체의 오퍼레이터 수정으로
struct cmp 
{
	bool operator()(pair<int,int> a, pair<int, int> b)
	{
		return a.second < a.second;
	}
};

void dijkstra(const vector<vector<pair<int, int>>>& way, vector<int>& distance, int start)
{
	distance[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	pq.push({ start, 0 });
	while (!pq.empty())
	{
		pair<int, int> node = pq.top();
		pq.pop();

		if (node.second > distance[node.first])
			continue;

		for (const pair<int, int> e : way[node.first])
		{
			int v = e.first;
			int newDist = distance[node.first] + e.second;
			if (newDist < distance[v])
			{
				distance[v] = newDist;
				pq.push({ v, newDist });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	// 한 연결당 100000 이지만 시작 지점에서 각 노드에 가는 비용의 합이 100000이 넘을 수 있으므로
	int MAX = 100000 * N - 1;
	vector<vector<pair<int, int>>> way(N + 1);
	// 출발 지점의 노드들에 대한 최소 거리들
	vector<int> distance(N + 1, MAX);
	cin >> M;
	while (M--)
	{
		int idx;
		pair<int, int> node;
		cin >> idx;
		cin >> node.first >> node.second;
		way[idx].push_back(node);
	}
	int start, dest;
	cin >> start >> dest;
	dijkstra(way, distance, start);
	cout << distance[dest];
	

	return 0;
}