#include<iostream>
using namespace std;
int N;
int MAP[100][100] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int mid = 0; mid < N; mid++) {
		for (int start = 0; start < N; start++) {
			for (int end = 0; end < N; end++) {
				if (MAP[start][mid] && MAP[mid][end]) {
					MAP[start][end] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << MAP[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}