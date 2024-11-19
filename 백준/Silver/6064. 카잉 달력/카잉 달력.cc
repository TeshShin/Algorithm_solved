#include<iostream>
using namespace std;

int gcd(int a, int b) { // a < b 라도, 첫 재귀에서 둘의 위치가 바뀐다.
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int calendar(int m, int n, int x, int y) {
	int max = lcm(m, n);
	for (int i = x; i <= max; i += m) {
		int ny = i % n;
		if (ny == 0) ny = n;
		if (ny == y) {
			return i;
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m, x, y;
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;
		cout << calendar(m, n, x, y) << '\n';
	}


	return 0;
}