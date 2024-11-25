#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, H;
queue<int> q1;
queue<int> q2;
queue<int> q3;
queue<int> day;
int bfs(vector<vector<vector<int>>>& map, vector<vector<vector<bool>>>& checkmap) {
	if (q1.empty()) {
		return -1;
	}
	int movez[6] = { 0, 0, 0, 0, 1, -1 };
	int movey[6] = { 0, 0, 1, -1, 0, 0 };
	int movex[6] = { 1, -1, 0, 0, 0, 0 };
	int yesterday;
	while (!q1.empty()) {
		int z = q1.front();
		int y = q2.front();
		int x = q3.front();
		yesterday = day.front();
		q1.pop();
		q2.pop();
		q3.pop();
		day.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + movez[i];
			int ny = y + movey[i];
			int nx = x + movex[i];
			if (nz < H && nz >= 0 && ny < N && ny >= 0 && nx < M && nx >= 0 && !checkmap[nz][ny][nx]) {
				if (map[nz][ny][nx] == 0) {
					map[nz][ny][nx] = 1;
					q1.push(nz);
					q2.push(ny);
					q3.push(nx);
					day.push(yesterday + 1);
					checkmap[nz][ny][nx] = true;
				}
			}
		}
	}

	bool checkzero = false;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0) {
					checkzero = true;
				}
			}
		}
	}
	if (checkzero) {
		return -1;
	}

	return yesterday;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N >> H;
	vector<vector<vector<int>>> map(H, vector<vector<int>>(N, vector<int>(M, 0)));
	vector<vector<vector<bool>>> checkmap(H, vector<vector<bool>>(N, vector<bool>(M, 0)));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == -1) {
					checkmap[i][j][k] = true;
				}
				else if (map[i][j][k] == 1) {
					q1.push(i);
					q2.push(j);
					q3.push(k);
					day.push(0);	
					checkmap[i][j][k] = true;
				}
			}
		}
	}
	cout << bfs(map, checkmap);
	//check
	//cout << "\n";

	//for (int i = 0; i < H; i++) {
	//	for (int j = 0; j < N; j++) {
	//		for (int k = 0; k < M; k++) {
	//			cout << map[i][j][k] << " ";
	//		}
	//		cout << "\n";
	//	}

	//}
}