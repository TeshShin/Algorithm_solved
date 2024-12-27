#include<iostream>
#include<vector>
using namespace std;
#define MAX 8

int N, M;
bool visited[MAX] = { 0 };
vector<int> answer;

void solve(int start);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	solve(0);

	return 0;
}

void solve(int start) {
	if (start == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << " ";
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			answer.push_back(i + 1);
			solve(start + 1);
			visited[i] = false;
			answer.pop_back();
		}
	}
}