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
	solve(0, -1);

	return 0;
}

void solve(int depth, int start) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = start + 1; i < N; i++) {
			answer.push_back(i + 1);
			solve(depth + 1, i);
			answer.pop_back();
		}
	}
}
