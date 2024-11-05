#include<iostream>
using namespace std;

int square[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= 4; i++) {
		if (i == 1) {
			for (int j = 1; j * j <= n; j++) {
				square[j * j] = i;
			}
		}
		else {
			for (int k = 1; k <= n; k++) {
				if (square[k] == i - 1) {
					for (int j = 1; k + j * j <= n; j++) {
						if (square[k + j * j] == 0) {
							square[k + j * j] = i;
						}
					}
				}
			}
		}
		if (square[n] == i) {
			cout << i;
			break;
		}
	}

	return 0;
}