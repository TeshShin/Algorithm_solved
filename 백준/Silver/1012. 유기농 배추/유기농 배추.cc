#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int dfs(vector<vector<bool>>& map, int y, int x) {
	int move[4] = { -1, 1, 0, 0 };
	stack<int> stackx;
	stack<int> stacky;
	stackx.push(x);
	stacky.push(y);
	int count = 0;

	while (!stackx.empty()) {
		x = stackx.top();
		y = stacky.top();
		stackx.pop();
		stacky.pop();
		if (map[y][x]) {
			count++;
			map[y][x] = 0;

			for (int i = 0; i < 4; i++) {
				int nx = x + move[i];
				int ny = y + move[3 - i];
				if (nx < map[0].size() && nx >= 0 && ny < map.size() && ny >= 0 && map[ny][nx]) {
					stackx.push(nx);
					stacky.push(ny);
				}
			}
		}
	}
	return count;
}

int bfs(vector<vector<bool>>& map, int y, int x) {
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
		if (map[y][x]) {
			count++;
			map[y][x] = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + move[i];
				int ny = y + move[3 - i];
				if (0 <= nx && 0 <= ny && nx < map[0].size() && ny < map.size() && map[ny][nx]) {
					qx.push(nx);
					qy.push(ny);
				}
			}
		}
	}
	return count;
}


int main() {
	int test;
	int N, M, K;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> M >> N >> K;
		vector<vector<bool>> map(N, vector<bool>(M, 0));
		int X, Y;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			map[Y][X] = 1;
		}
		vector<int> list;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x]) {
					list.push_back(dfs(map, y, x));
				}
			}
		}

		cout << list.size() << endl;
	}

	return 0;
}