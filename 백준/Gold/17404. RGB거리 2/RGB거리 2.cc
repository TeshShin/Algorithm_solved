#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vector<vector<int>> houses(N, vector<int>(3));
	const int R = 0;
	const int G = 1;
	const int B = 2;
	const int INF = 1'000'000;
	for (int i = 0; i < N; i++)
	{
		for (int color = 0; color < 3; color++)
		{
			cin >> houses[i][color];
		}
	}
	int answer = INF;
	for (int color = 0; color < 3; color++)
	{
		vector<vector<int>> dp(N, vector<int>(3, INF));
		dp[0][color] = houses[0][color];
		dp[0][(color + 1) % 3] = INF;
		dp[0][(color + 2) % 3] = INF;
		for (int i = 1; i < N; i++)
		{
			dp[i][R] = houses[i][R] + min(dp[i - 1][G], dp[i - 1][B]);
			dp[i][G] = houses[i][G] + min(dp[i - 1][R], dp[i - 1][B]);
			dp[i][B] = houses[i][B] + min(dp[i - 1][G], dp[i - 1][R]);
		}
		answer = min(answer, min(dp[N - 1][(color + 1) % 3], dp[N - 1][(color + 2) % 3]));
	}
	cout << answer;

	return 0;
}