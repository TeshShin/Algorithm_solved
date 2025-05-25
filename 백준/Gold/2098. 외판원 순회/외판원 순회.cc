#include<iostream>
using namespace std;
#define INF 16'000'000
int n, map[16][16];
int dp[16][1 << 16];

int dfs(int cur, int visit)
{
	// 탐색 완료
	if (visit == (1 << n) - 1)
	{
		if (map[cur][0] == 0) // 이동 불가
		{
			return INF;
		}
		return map[cur][0];
	}
	if (dp[cur][visit] != -1) // 이미 탐색 했으면
		return dp[cur][visit];

	dp[cur][visit] = INF;

	for (int i = 0; i < n; i++)
	{
		if (map[cur][i] == 0) // 길 X
			continue;
		if ((visit & (1 << i)) == (1 << i)) // 이미 방문
			continue;
		// 시작 -> 현재 도시로 가는 거리 vs 방문하지 않은 다른 도시로 가는 거리
		// visit | (1 << i) : 현재도시를 방문했다는 의미
		dp[cur][visit] = min(dp[cur][visit], map[cur][i] + dfs(i, visit | 1 << i));
	}
	return dp[cur][visit];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 1 << 16; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << dfs(0, 1);

	return 0;
}