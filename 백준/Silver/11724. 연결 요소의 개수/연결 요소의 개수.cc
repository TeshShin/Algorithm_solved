#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;


void dfs(vector<vector<bool>>& map, int x) {
	stack<int> st;
	st.push(x);

	while (!st.empty()) {
		x = st.top();
		st.pop();
		for (int i = 0; i < map.size(); i++) {
			if (map[x][i]) {
				st.push(i);
				map[x][i] = 0;
				map[i][x] = 0;
			}
		}
	}
}

void bfs(vector<vector<bool>>& map, int x) {
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < map.size(); i++) {
			if (map[x][i]) {
				q.push(i);
				map[x][i] = 0;
				map[i][x] = 0;
			}
		}
	}
}


int main() {
	int N, M;
	int count = 0;
	cin >> N >> M;
	vector<vector<bool>> map(N, vector<bool>(N, 0));
	vector<bool> alonecheck(N, 0);
	for (int i = 0; i < M; i++) {
		int first, second;
		cin >> first >> second;
		first--;
		second--;
		map[first][second] = 1;
		map[second][first] = 1;
		alonecheck[first] = 1;
		alonecheck[second] = 1;
	}
	for (int i = 0; i < N; i++) {
		if (!alonecheck[i]) {
			count++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) {
				bfs(map, i);
				count++;
			}
		}
	}
	cout << count << endl;

	return 0;
}