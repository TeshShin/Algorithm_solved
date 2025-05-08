#include<iostream>

#define MAX 100 * 100001
using namespace std;

int N, M;
int MAP[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = MAX;
		}
	}

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if(cost < MAP[from][to])
			MAP[from][to] = cost;
	}

	for (int mid = 1; mid <= N; mid++) {
		for (int start = 1; start <= N; start++) {
			for (int end = 1; end <= N ; end++) {
				if (start == end) continue;
				MAP[start][end] = min(MAP[start][end], MAP[start][mid] + MAP[mid][end]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == MAX) cout << 0 << " ";
			else cout << MAP[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}