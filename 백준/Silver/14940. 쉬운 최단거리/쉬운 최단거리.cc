#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;


void bfs(vector<vector<int>>& map, vector<vector<bool>>& checkmap, int goal[]) {
	int movex[4] = { 1 , 0 , 0, -1 };
	int movey[4] = { 0 , 1, -1, 0 };
	queue<int> q1;
	queue<int> q2;
	q1.push(goal[0]);
	q2.push(goal[1]);
	map[goal[0]][goal[1]] = 0;

	while (!q1.empty()) {
		
		int x = q1.front();
		int y = q2.front();

		q1.pop();
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + movex[i];
			int ny = y + movey[i];
			if (nx < N && nx >= 0 && ny < M && ny >= 0 && !checkmap[nx][ny]) {
				if (map[nx][ny]) {
					map[nx][ny] = map[x][y] + 1;
					q1.push(nx);
					q2.push(ny);
					checkmap[nx][ny] = true;
				}
			}
		}
	}
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	int goal[2];
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> checkmap(N, vector<bool>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				goal[0] = i;
				goal[1] = j;
			}
		}
	}
	bfs(map, checkmap, goal);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (checkmap[i][j] || !map[i][j]) {
				cout << map[i][j] << " ";
			}
			else {
				cout << -1 << " ";
			}
		}
		cout << "\n";
	}

}