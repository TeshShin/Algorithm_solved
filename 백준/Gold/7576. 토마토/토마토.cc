#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
queue<int> q1;
queue<int> q2;
queue<int> day;
int bfs(vector<vector<int>>& map, vector<vector<bool>>& checkmap) {
	if (q1.empty()) {
		return -1;
	}
	int movex[4] = { 1 , 0 , 0, -1 };
	int movey[4] = { 0 , 1, -1, 0 };
	int maxday = 0;

	while (!q1.empty()) {
		int x = q1.front();
		int y = q2.front();
		int yesterday = day.front();
		maxday = max(maxday, yesterday);
		q1.pop();
		q2.pop();
		day.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + movex[i];
			int ny = y + movey[i];
			if (nx < N && nx >= 0 && ny < M && ny >= 0 && !checkmap[nx][ny]) {
				if (map[nx][ny] == 0) {
					map[nx][ny] = 1;
					q1.push(nx);
					q2.push(ny);
					day.push(yesterday + 1);
					checkmap[nx][ny] = true;
				}
			}
		}
	}

	bool checkzero = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				checkzero = true;
			}
		}
	}
	if (checkzero) {
		return -1;
	}

	return maxday;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> checkmap(N, vector<bool>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				checkmap[i][j] = true;
			}
			else if (map[i][j] == 1) {
				q1.push(i);
				q2.push(j);
				day.push(0);
				checkmap[i][j] = true;
			}
		}
	}
	cout << bfs(map, checkmap);
	//check
	//cout << "\n";

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
}