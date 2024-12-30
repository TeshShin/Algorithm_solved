#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 8

int N, M;
vector<int> inputlist;

bool visited[MAX] = { 0 };
vector<int> answer;

void solve(int depth);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int input;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputlist.push_back(input);
	}
	sort(inputlist.begin(), inputlist.end());

	solve(0);

	return 0;
}
void solve(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			answer.push_back(inputlist[i]);
			solve(depth + 1);
			visited[i] = false;
			answer.pop_back();
		}
	}


}