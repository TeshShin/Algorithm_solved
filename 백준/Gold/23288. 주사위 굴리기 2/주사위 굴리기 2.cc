#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;
int N, M, K;

// 0 : 동, 1 : 남, 2 : 서, 3 : 북
int dCol[4] = { 1, 0, -1, 0 };
int dRow[4] = { 0, 1, 0 , -1 };
// 인덱스  0 : 윗면, 1 : 북, 2 : 우측, 3 : 좌측, 4 : 남, 5 : 아랫면
const int top = 0;
const int north = 1;
const int east = 2;
const int west = 3;
const int south = 4;
const int bottom = 5;

bool CanGo(int a, int b)
{
	return a > 0 && b > 0 && a <= N && b <= M;
}


void BFS(const vector<vector<int>>& map, vector<vector<int>>& scoreMap, int r, int c)
{
	queue<P> q;
	vector<P> mem;
	q.push({ r, c });
	int num = map[r][c];
	while (!q.empty())
	{
		P curr = q.front();
		q.pop();
		if (scoreMap[curr.first][curr.second] != 0) continue;
		scoreMap[curr.first][curr.second] = -1;
		mem.push_back({ curr.first, curr.second });
		for (int i = 0; i < 4; i++)
		{
			int row = curr.first + dRow[i];
			int col = curr.second + dCol[i];
			if (CanGo(row, col) && map[row][col] == num && scoreMap[row][col] == 0)
			{
				q.push({ row, col });
			}
		}
	}
	int size = static_cast<int>(mem.size());
	int score = num * size;
	for (int i = 0; i < size; i++)
	{
		P curr = mem[i];
		scoreMap[curr.first][curr.second] = score;
	}
}

void BuildScoreMap(const vector<vector<int>>& map, vector<vector<int>>& scoreMap)
{

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			if (scoreMap[r][c] != 0) continue;
			BFS(map, scoreMap, r, c);
		}
	}

}

void MoveDice(int(&dice)[6], int dir)
{
	int temp[6];
	switch (dir)
	{
	case 0:
		temp[top] = dice[west];
		temp[north] = dice[north];
		temp[east] = dice[top];
		temp[west] = dice[bottom];
		temp[south] = dice[south];
		temp[bottom] = dice[east];
		break;
	case 1:
		temp[top] = dice[north];
		temp[north] = dice[bottom];
		temp[east] = dice[east];
		temp[west] = dice[west];
		temp[south] = dice[top];
		temp[bottom] = dice[south];
		break;
	case 2:
		temp[top] = dice[east];
		temp[north] = dice[north];
		temp[east] = dice[bottom];
		temp[west] = dice[top];
		temp[south] = dice[south];
		temp[bottom] = dice[west];
		break;
	case 3:
		temp[top] = dice[south];
		temp[north] = dice[top];
		temp[east] = dice[east];
		temp[west] = dice[west];
		temp[south] = dice[bottom];
		temp[bottom] = dice[north];
		break;
	}
	for (int i = 0; i < 6; i++)
	{
		dice[i] = temp[i];
	}
}

void ClockRotate(int& dir)
{
	dir = (dir + 1) % 4;
}
void CounterClockRotate(int& dir)
{
	dir = (dir + 3) % 4;
}
void Flip(int& dir)
{
	dir = (dir + 2) % 4;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	vector<vector<int>> map(N + 1, vector<int>(M + 1, 0));
	vector<vector<int>> scoreMap(N + 1, vector<int>(M + 1, 0));
	int dice[6] = { 1, 2, 3, 4, 5, 6 };
	int dir = 0;
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			cin >> map[r][c];
		}
	}
	BuildScoreMap(map, scoreMap);
	int row = 1, col = 1, score = 0;
	for (int i = 0; i < K; i++)
	{
		if (!CanGo(row + dRow[dir], col + dCol[dir]))
			Flip(dir);
		row += dRow[dir];
		col += dCol[dir];
		MoveDice(dice, dir);
		score += scoreMap[row][col];
		if (dice[bottom] > map[row][col])
		{
			ClockRotate(dir);
		}
		else if (dice[bottom] < map[row][col])
		{
			CounterClockRotate(dir);
		}
	}
	cout << score;

	return 0;
}