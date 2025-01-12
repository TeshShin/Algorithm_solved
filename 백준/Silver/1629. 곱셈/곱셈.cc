#include<iostream>
using namespace std;

long long A, B, C;

long long solve(long long b) {
	if (b == 1) return A % C;

	long long x = solve(b / 2) % C;
	if (b % 2 == 0) return x * x % C;
	return x * x % C * A % C;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C;
	cout << solve(B);
	return 0;
}