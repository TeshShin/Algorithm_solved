#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M; // N은 투자 금액, M은 회사 번째
	vector<vector<int>> graph(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
	for(int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		for (int j = 1; j <= M; j++)
		{
			cin >> graph[i][j];
		}
	}
	// dp[N][M] = M번째 회사에 투자한 액수 N
	// dp[N][0] = 투자한 액수 N의 최대 이익
	for (int i = 1; i <= M; i++) // 현재 선택한 회사
	{
		for (int j = N; j >= 0; j--) // 현재까지 총 투자한 금액
		{
			for (int k = 0; k <= j; k++) // i번째 회사에 투자할 금액
			{
				if (dp[j][0] < dp[j - k][0] + graph[k][i]) // 총 투자한 금액에서 최대 가치
				{
					dp[j][0] = dp[j - k][0] + graph[k][i]; // i번째의 회사에 k만큼 투자

					for (int t = 1; t <= M; t++) // 현재가 최대 가치이므로 업데이트
					{
						if (t == i) dp[j][i] = k;
						else	dp[j][t] = dp[j - k][t];
					}
				}
			}
		}
	}
	cout << dp[N][0] << '\n';

	for (int i = 1; i <= M; i++)
	{
		cout << dp[N][i] << ' ';
	}
}