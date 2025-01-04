#include<iostream>
#include<vector>
using namespace std;
#define MAX 100001
// 양방향임에 주의
int N;
bool visited[MAX] = { 0 };
vector<int> node[MAX];
int answer[MAX];
void dfs(int k);
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}

	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << answer[i] << '\n';
	}


	return 0;
}

void dfs(int k) {
	visited[k] = true;
	for (int i = 0; i < node[k].size(); i++) {
		int next = node[k][i];
		if (!visited[next]) {
			answer[next] = k;
			dfs(next);
		}
	}
}