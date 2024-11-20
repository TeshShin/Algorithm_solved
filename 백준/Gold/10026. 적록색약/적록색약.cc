#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int d[4] = { -1, 1, 0, 0 };
int N;


int bfs(char map[100][100]) {
	bool visit[100][100] = { false };
	int cnt = 0;
	queue<int> qx;
	queue<int> qy;
	for(int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				qx.push(i);
				qy.push(j);
				while (!qx.empty()) {
					int x = qx.front();
					int y = qy.front();
					visit[x][y] = true;
					qx.pop();
					qy.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + d[k];
						int ny = y + d[3 - k];
						if (0 <= nx && 0 <= ny && nx < N && ny < N) {
							if (!visit[nx][ny] && map[nx][ny] == map[x][y]) {
								qx.push(nx);
								qy.push(ny);
								visit[nx][ny] = true;
							}
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	char map[100][100];
	char weakmap[100][100];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'G') {
				weakmap[i][j] = 'R';
			}
			else {
				weakmap[i][j] = map[i][j];
			}
		}
	}
	cout << bfs(map) << " " << bfs(weakmap);

	return 0;
}