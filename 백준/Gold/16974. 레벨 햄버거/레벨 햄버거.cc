#include <iostream>
using namespace std;
long long Hamburger[51], Patty[51];
long long N, X;

long long Solve(long long n, long long x)
{
	if (n == 0) return 1; // 레벨 0 이면 패티 하나

	if (x == 1) return 0; // x가 1이면 번 하나

	if (x <= 1 + Hamburger[n - 1]) return Solve(n - 1, x - 1);
	else if (x == 1 + Hamburger[n - 1] + 1) return Patty[n - 1] + 1;
	else if (x <= 1 + Hamburger[n - 1] + 1 + Hamburger[n - 1]) return Patty[n - 1] + 1 + Solve(n - 1, x - (Hamburger[n - 1] + 1 + 1));
	else if (x == 1 + Hamburger[n - 1] + 1 + Hamburger[n - 1] + 1) return Patty[n - 1] + 1 + Patty[n - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> X;

	Hamburger[0] = 1;
	Patty[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		Hamburger[i] = 1 + Hamburger[i - 1] + 1 + Hamburger[i - 1] + 1;
		Patty[i] = Patty[i - 1] + 1 + Patty[i - 1];
	}

	cout << Solve(N, X);
}