#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using V2 = vector<vector<int>>;
using P = pair<int, int>;
using V2P = vector<vector<P>>;
int N;
const int wormholeIndex = 6;
enum EDirection
{
	Left,
	Up,
	Right,
	Down
};
// 0: 왼쪽, 1: 위쪽, 2: 오른쪽, 3: 아래쪽
int dRow[4] = { 0, -1, 0, 1 };
int dCol[4] = { -1, 0, 1, 0 };

void Flip(EDirection& dir)
{
	switch (dir)
	{
	case EDirection::Left:
		dir = EDirection::Right;
		break;
	case EDirection::Up:
		dir = EDirection::Down;
		break;
	case EDirection::Right:
		dir = EDirection::Left;
		break;
	case EDirection::Down:
		dir = EDirection::Up;
		break;
	}
}

void ChangeDirection(EDirection& dir, int blockNum)
{
	switch (blockNum)
	{
	case 1:
		if (dir == Down) dir = Right;
		else if (dir == Left) dir = Up;
		else Flip(dir);
		break;
	case 2:
		if (dir == Up) dir = Right;
		else if (dir == Left) dir = Down;
		else Flip(dir);
		break;
	case 3:
		if (dir == Up) dir = Left;
		else if (dir == Right) dir = Down;
		else Flip(dir);
		break;
	case 4:
		if (dir == Down) dir = Left;
		else if (dir == Right) dir = Up;
		else Flip(dir);
		break;
	case 5:
		Flip(dir);
		break;
	}
}

void GoWormHole(const V2P& wormhole, int& row, int& col, int blockNum)
{
	int idx = blockNum - wormholeIndex;
	if (wormhole[idx][0].first == row && wormhole[idx][0].second == col)
	{
		row = wormhole[idx][1].first;
		col = wormhole[idx][1].second;
	}
	else
	{
		row = wormhole[idx][0].first;
		col = wormhole[idx][0].second;
	}
}
bool HitWall(int& row, int& col, EDirection dir)
{
	if (row < 0)
	{
		row = 0;
		return true;
	}
	else if (row > N - 1)
	{
		row = N - 1;
		return true;
	}
	else if (col < 0)
	{
		col = 0;
		return true;
	}
	else if (col > N - 1)
	{
		col = N - 1;
		return true;
	}
	else return false;
}
int PlayPinBall(const V2& graph, const V2P& wormhole, int row, int col, EDirection dir)
{
	int score = 0;
	int startRow = row, startCol = col;
	while (true)
	{
		row += dRow[dir];
		col += dCol[dir];
		if (HitWall(row, col, dir))
		{
			score++;
			Flip(dir);
		}
		int blockNum = graph[row][col];
		// 1. 블랙홀인지, 2. 웜홀인지, 3. 블럭인지 4. 벽에 부딪힌건지
		if (blockNum == -1 || (row == startRow && col == startCol)) break;
		else if (blockNum >= 6)
		{
			GoWormHole(wormhole, row, col, blockNum);
		}
		else if (blockNum != 0)
		{
			score++;
			ChangeDirection(dir, blockNum);
		}
	}
	return score;
}

int StartPinBall(const V2& graph, const V2P& wormhole)
{
	int maxScore = 0;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			if (graph[row][col] != 0) continue;
			for (int dir = 0; dir < 4; dir++)
			{
				int score = PlayPinBall(graph, wormhole, row, col, static_cast<EDirection>(dir));
				if (maxScore < score) maxScore = score;
			}
		}
	}
	return maxScore;
}



int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
		V2 graph(N, vector<int>(N, 0));
		V2P wormhole(5);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> graph[i][j];
				if (graph[i][j] >= 6)
				{
					wormhole[graph[i][j] - wormholeIndex].push_back({ i, j });
				}
			}
		}
		cout << '#' << test_case << ' ' << StartPinBall(graph, wormhole) << '\n';
	}
	return 0;
}