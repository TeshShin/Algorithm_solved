#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int MAP[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int a = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				MAP[i][j] = 0;
			}
			else {
				MAP[i][j] = 100;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		MAP[a][b] = 1;
		MAP[b][a] = 1;
	}

	for (int mid = 1; mid < N + 1; mid++) {
		for (int start = 1; start < N + 1; start++) {
			for (int end = 1; end < N + 1; end++) {
				if (start == end) continue;
				MAP[start][end] = min(MAP[start][end], MAP[start][mid] + MAP[mid][end]);
			}
		}
	}
	
	int minsum = 50000; // 1~99까지의 합보단 커야함.
	int minidx = 1;
	for (int i = 1; i < N + 1; i++) {
		int sum = 0;
		for (int j = 1; j < N + 1; j++) {
			if (i == j) continue;
			sum += MAP[i][j];
		}
		if (sum < minsum) {
			minsum = sum;
			minidx = i;
		}
	}

	cout << minidx;

	return 0;
}