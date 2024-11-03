#include<iostream>


using namespace std;

long long P[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	for (int i = 6; i <= 100; i++) {
		P[i] = P[i - 1] + P[i - 5];
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		cout << P[N] << '\n';
	}

	return 0;
}