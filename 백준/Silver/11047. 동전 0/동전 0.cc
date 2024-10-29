#include<iostream>


using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	int money[11];
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}
	int cnt = 0;
	for (int i = N ; i > 0; i--) {
		if (!K) {
			break;
		}
		if (K >= money[i - 1]) {
			cnt += (K / money[i - 1]);
			K -= (K / money[i - 1]) * money[i - 1];
			// check
			//cout << "used : " << money[i - 1] << '\n';
			continue;
		}
	}
	cout << cnt;
	return 0;
}