#include<iostream>
using namespace std;

int N;
int dp[500][500];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}
	// Print
	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
	*/
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			dp[i - 1][j - 1] += max(dp[i][j], dp[i][j - 1]);
		}
	}
	cout << dp[0][0];

	return 0;
}