#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int T, N, teamCount;

void Dfs(const vector<int>& list, int current, vector<bool>& visited, vector<bool>& finished)
{
	visited[current] = true;
	int next = list[current];
	if (!visited[next])
	{
		Dfs(list, next, visited, finished);
	}
	else if(!finished[next])
	{
		int cnt = 1;
		for (int i = next; i != current; i = list[i])
		{
			cnt++;
		}
		teamCount += cnt;
	}
	finished[current] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		teamCount = 0;
		cin >> N;
		vector<int> list(N + 1);
		vector<bool> visited(N + 1);
		vector<bool> finished(N + 1);
		for (int i = 1; i <= N; i++)
		{
			cin >> list[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (finished[i]) continue;
			Dfs(list, i, visited, finished);
		}
		cout << N - teamCount << '\n';
	}

	return 0;
}