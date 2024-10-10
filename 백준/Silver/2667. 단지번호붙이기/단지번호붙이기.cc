#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int dfs(vector<vector<bool>>& map, int x, int y) {
	int move[4] = { -1, 1, 0, 0 };
	stack<int> stackx;
	stack<int> stacky;
	stackx.push(x);
	stacky.push(y);
	int count = 0;

	while (!stackx.empty()) {
		x = stackx.top();
		y = stacky.top();
		if (map[x][y]) {
			count++;
			map[x][y] = 0;
			stackx.pop();
			stacky.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + move[i];
				int ny = y + move[3 - i];
				if (nx < size(map) && nx >= 0 && ny < size(map) && ny >= 0 && map[nx][ny]) {
					stackx.push(nx);
					stacky.push(ny);
				}
			}
		}
		else {
			stackx.pop();
			stacky.pop();
		}
	}
	return count++;
}

void bfs(vector<vector<bool>>& map, int x, int y) {

}


int main() {
	int N;
	cin >> N;
	vector<vector<bool>> map(N, vector<bool>(N, 0));
	string line;
	vector<int> list;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < N; j++) {
			if (line[j] == '1') {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) {
				list.push_back(dfs(map, i, j));
			}
		}
	}

	sort(list.begin(), list.end());
	cout << list.size() << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}
	
	return 0;
}