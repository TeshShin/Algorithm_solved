#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N, E;
vector<int> visited(100);

int dfs(vector<vector<int>> G, int first) {
	int count = 0;
	stack<int> s1;
	visited[0] = true;
	s1.push(first);
	while (!s1.empty()) {
		first = s1.top();
		s1.pop();
		for (int i = 0; i < N; i++) {
			if (G[first][i] && !visited[i]) {
				s1.push(i);
				visited[i] = true;
				count++;
			}
		}
	}
	return count;
}



int main() {

	cin >> N >> E;
	vector<vector<int>> G(N, vector<int> (N, 0));
	for (int i = 0; i < E; i++) {
		int first, second;
		cin >> first >> second;
		first--;
		second--;
		G[first][second]++;
		G[second][first]++;
	}
	cout << dfs(G, 0);

	return 0;
}