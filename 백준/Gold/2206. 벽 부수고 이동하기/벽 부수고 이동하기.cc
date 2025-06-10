#include<iostream>
#include<queue>
using namespace std;

int maze[1000][1000][2];
int N, M;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int BFS()
{
	queue<pair<int, pair<int, int>>> q;
	maze[0][0][0] = 1;
	q.push({ 0, {0, 0} });
	while (!q.empty())
	{
		int broken = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (y == N - 1 && x == M - 1)
			return maze[y][x][broken];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;

			if (maze[ny][nx][0] == 0)
			{
				// 이미 부순 후에 왔던 곳이라면,
				if (broken == 1 && maze[ny][nx][broken])
					continue;
				maze[ny][nx][broken] = maze[y][x][broken] + 1;
				q.push({ broken, {ny, nx} });
			}
			// 벽이라면 부술지 정하기
			else if (maze[ny][nx][0] == 1)
			{
				if (broken)
					continue;
				maze[ny][nx][1] = maze[y][x][0] + 1;
				q.push({ 1, {ny, nx} });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char input;
			cin >> input;
			maze[i][j][0] = input - '0';
		}
	}
	cout << BFS();
	return 0;
}