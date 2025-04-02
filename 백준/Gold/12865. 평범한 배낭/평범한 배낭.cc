#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	int item[101][2];
	for (int i = 1; i <= N; i++)
	{
		cin >> item[i][0] >> item[i][1];
	}
	for (int i = 1; i <= K; i++) // 무게
	{
		for (int j = 1; j <= N; j++) // 물품
		{
			if (item[j][0] <= i) // 해당 무게에 담을 수 있는 물품일 경우
			{
				dp[j][i] = max(dp[j - 1][i], dp[j - 1][i - item[j][0]] + item[j][1]);
			}
			else // 해당 무게에 현재 물품을 못담는 경우
			{
				dp[j][i] = dp[j - 1][i];
			}
		}
	}
	cout << dp[N][K];
	return 0;
}