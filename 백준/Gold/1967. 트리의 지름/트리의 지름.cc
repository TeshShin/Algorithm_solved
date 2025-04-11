#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<pair<int, int>> graph[10001];

int N;

void dfs()
{
	int ans = 0;
	stack<int> st;
	for (int i = 1; i <= N; i++)
	{
		vector<int> dist(N + 1, -1);
		st.push(i);
		dist[i] = 0;
		while (!st.empty())
		{
			int curr = st.top();
			st.pop();

			for (const pair<int, int> next : graph[curr])
			{
				if (dist[next.first] > -1) continue;
				st.push(next.first);
				dist[next.first] = dist[curr] + next.second;
				if (ans < dist[next.first]) ans = dist[next.first];
			}
		}
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	dfs();


	return 0;
}