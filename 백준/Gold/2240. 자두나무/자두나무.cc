#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int T, W;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T >> W;
	vector<vector<int>> dp(T + 1, vector<int>(W + 1, 0));
	vector<int> time(T + 1, 0);
	for (int i = 1; i <= T; i++)
		cin >> time[i];

	for (int i = 1; i <= T; i++)
	{
		for (int j = 0; j <= W && j <= i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + ((j % 2) != (time[i] % 2));
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + ((j % 2) != (time[i] % 2));
			}

		}
	}
	int answer = 0;
	for (int i = 0; i <= W; i++)
	{
		if (answer < dp[T][i]) answer = dp[T][i];
	}
	cout << answer;
	return 0;
}