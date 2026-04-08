#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

using P = pair<int, int>;

int C, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> C >> N;
	vector<P> citys(N);

	for (int i = 0; i < N; i++)
	{
		cin >> citys[i].first >> citys[i].second;
	}
	const int INF = 1e9;
	int limit = C + 100;
	vector<int> dp(limit + 1, INF);
	dp[0] = 0;
	for (const P& city : citys)
	{
		int cost = city.first;
		int customer = city.second;
		for (int i = customer; i <= limit; i++)
		{
			dp[i] = min(dp[i], dp[i - customer] + cost);
		}
	}
	
	int answer = INF;
	for (int i = C; i <= limit; i++)
	{
		answer = min(answer, dp[i]);
	}
	cout << answer;

	return 0;
}