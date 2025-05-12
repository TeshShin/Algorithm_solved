#include<iostream>
using namespace std;
#define MOD 1000000007

int M, N, S;

long long bInversed(int b, int power)
{
	if (power == 1) return b;
	// 지수가 홀수 라면 b * b^(power-1)
	// b^(power-1)는 짝수가 되므로
	// ==> b^(power/2) * b^(power/2) 로 됨
	if (power % 2 == 1) return b * bInversed(b, power - 1) % MOD;
	long long var = bInversed(b, power / 2) % MOD;
	return var * var % MOD;
}

long long ans = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	while (M--)
	{
		cin >> N >> S;

		long long val = S * bInversed(N, MOD - 2) % MOD;
		ans += (val % MOD);
	}
	cout << ans % MOD;
	return 0;
}