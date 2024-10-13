#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;

int bfs(vector<vector<int>>& map, int y, int x) {
	int movex[4] = { 1, 0, 0, -1 };
	int movey[4] = { 0, 1, -1, 0};
	queue<int> qx;
	queue<int> qy;
	qx.push(x);
	qy.push(y);
	while (!qx.empty()) {
		x = qx.front();
		y = qy.front();
		qx.pop();
		qy.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + movex[i];
			int ny = y + movey[i];
			if (nx < map[0].size() && nx >= 0 && ny < size(map) && ny >= 0 && map[ny][nx] == 1) {
				map[ny][nx] = map[y][x] + 1;
				qx.push(nx);
				qy.push(ny);
			}
		}
	}
	return map[map.size() - 1][map[0].size() - 1];
}


int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			if (line[j] == '1') {
				map[i][j] = 1;
			}
		}
	}
	cout << bfs(map, 0, 0);
	
	return 0;
}