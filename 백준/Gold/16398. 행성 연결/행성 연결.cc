#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

using ll = long long;
using p = pair<ll, int>; // {Cost, Node}
// pair의 기본 비교가 first -> second 순
struct cmp // second를 비교한 걸로 하고 싶으면 구조체의 비교 연산자 활용
{
	bool operator()(p a, p b)
	{
		return a.second > b.second; // cost 작은 게 우선
	}
};

int N;
ll edge[1001][1001];
bool visit[1001];

ll prim()
{
	ll answer = 0;
	
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ 0, 0 });

	while (!pq.empty())
	{
		ll dist = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (visit[curr]) continue;

		visit[curr] = true;
		answer += dist;

		for (int i = 0; i < N; i++)
		{
			ll nextDist = edge[curr][i];

			// 0이 "간선 없음"일 때만 유지
			if (!visit[i] && nextDist != 0)
			{
				pq.push({ nextDist, i });
			}
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> edge[i][j];
		}
	}

	cout << prim();
}