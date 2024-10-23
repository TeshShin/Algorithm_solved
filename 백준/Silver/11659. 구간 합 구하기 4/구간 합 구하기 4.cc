#include<iostream>
#include<vector>
using namespace std;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int dp[100000];
	cin >> dp[0];
	for (int i = 1; i < N; i++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	int first, second;

	for (int i = 0; i < M; i++) {
		cin >> first >> second;
		cout << dp[second - 1] - (dp[first - 2] * (first == 1 ? 0 : 1)) << '\n';
	}

	return 0;
}