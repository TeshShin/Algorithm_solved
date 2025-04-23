#include<iostream>
using namespace std;

int N, A[1000];
int dp[1001];
int Rdp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int maxNum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (A[i] > A[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}


	for (int i = N - 1; i >= 0; i--)
	{
		Rdp[i] = 1;
		for (int j = N - 1; j >= i; j--)
		{
			if (A[i] > A[j])
			{
				Rdp[i] = max(Rdp[i], Rdp[j] + 1);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (answer < dp[i] + Rdp[i] - 1) answer = dp[i] + Rdp[i] - 1;
	}
	cout << answer;
	return 0;
}