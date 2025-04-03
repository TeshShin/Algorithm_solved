#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> answer;

void solve(int depth, int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	solve(0, 1);

	return 0;
}

void solve(int depth, int start) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
	}
	else {
		for (int i = start; i <= N; i++) {
			answer.push_back(i);
			solve(depth + 1, i + 1);
			answer.pop_back();
		}
	}
}
