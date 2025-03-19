#include<iostream>
using namespace std;
string first;
string second;
int dp[1000][1000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> first;
	cin >> second;
	for (int i = 0; i < first.size(); i++)
	{
		for (int j = 0; j < second.size(); j++)
		{
			if (i == 0 && j == 0)
			{
				if (first[i] == second[j])
				{
					dp[i][j] = 1;
				}
			}
			else if (i == 0)
			{
				if (first[i] != second[j])
				{
					dp[i][j] = dp[i][j - 1];
				}
				else
				{
					dp[i][j] = 1;
				}
			}
			else if (j == 0)
			{
				if (first[i] != second[j])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = 1;
				}
			}
			else 
			{
				if (first[i] != second[j])
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
	}
	cout << dp[first.size() - 1][second.size() - 1];

	return 0;
}