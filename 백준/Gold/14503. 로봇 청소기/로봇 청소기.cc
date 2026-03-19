#include <iostream>
#include <vector>
using namespace std;

int N, M;
int r, c, d;

int dX[4] = { 0, 1, 0, -1 };
int dY[4] = { -1, 0, 1, 0 };

bool CanGo(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}

bool HasUncleanAdjacent(const vector<vector<int>>& map, int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int NextY = y + dY[i];
		int NextX = x + dX[i];

		if (CanGo(NextY, NextX) && map[NextY][NextX] == 0)
		{
			return true;
		}
	}
	return false;
}

int TurnLeft(int Dir)
{
	return (Dir + 3) % 4;
}

int Simulate(vector<vector<int>>& map)
{
	int CleanCnt = 0;
	int Y = r;
	int X = c;
	int Dir = d;

	while (true)
	{
		if (map[Y][X] == 0)
		{
			map[Y][X] = -1;
			CleanCnt++;
		}

		if (HasUncleanAdjacent(map, Y, X))
		{
			bool bMoved = false;

			for (int i = 0; i < 4; i++)
			{
				Dir = TurnLeft(Dir);

				int NextY = Y + dY[Dir];
				int NextX = X + dX[Dir];

				if (CanGo(NextY, NextX) && map[NextY][NextX] == 0)
				{
					Y = NextY;
					X = NextX;
					bMoved = true;
					break;
				}
			}
		}
		else
		{
			int BackY = Y - dY[Dir];
			int BackX = X - dX[Dir];

			if (!CanGo(BackY, BackX) || map[BackY][BackX] == 1)
			{
				return CleanCnt;
			}

			Y = BackY;
			X = BackX;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	cout << Simulate(map);

	return 0;
}