#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, M, S, E;
	cin >> N;
	vector<int> vec(N + 1);
	vector<vector<bool>> dp(N + 1, vector<bool>(N + 1));
	for (int i = 1; i <= N; i++)
	{
		cin >> vec[i];
		dp[i][i] = true;
	}
	for (int i = 1; i < N; i++)
	{
		dp[i][i + 1] = (vec[i] == vec[i + 1]);
	}
	for (int len = 3; len <= N; len++)
	{
		for (int s = 1; s + len - 1 <= N; s++)
		{
			int e = s + len - 1;
			if (vec[s] == vec[e] && dp[s + 1][e - 1])
			{
				dp[s][e] = true;
			}
		}
	}


	cin >> M;
	int s, e;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
	return 0;
}