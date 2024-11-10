#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int bfs(vector<vector<char>>& map, int y, int x) {
	int move[4] = { -1, 1, 0, 0 };
	queue<int> qx;
	queue<int> qy;
	qx.push(x);
	qy.push(y);
	int count = 0;
	while (!qx.empty()) {
		x = qx.front();
		y = qy.front();
		qx.pop();
		qy.pop();
		if (map[y][x] != 'X') {
			if (map[y][x] == 'P'){
				count++;
			}
			map[y][x] = 'X';
			for (int i = 0; i < 4; i++) {
				int nx = x + move[i];
				int ny = y + move[3 - i];
				if (0 <= nx && 0 <= ny && nx < map[0].size() && ny < map.size() && map[ny][nx] != 'X') {
					qx.push(nx);
					qy.push(ny);
				}
			}
		}
	}
	return count;
}


int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> map(N, vector<char>(M, 0));
	int x, y;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				y = i;
				x = j;
			}
		}
	}
	int result = bfs(map, y, x);
	if (!result) {
		cout << "TT";
	}
	else {
		cout << result;
	}
	return 0;
}