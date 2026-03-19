#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
using Tuple = tuple<int, int, int>;
int N, M;
int r, c, d;

int dX[4] = { 0, 1, 0, -1 };
int dY[4] = { -1, 0, 1, 0 };
bool CanGo(int y, int x)
{
	return x >= 0 && y >= 0 && x < M && y < N;
}

bool CheckNotClean(const vector<vector<int>>& map, const Tuple& curr)
{
	for (int i = 0; i < 4; i++)
	{
		int y = get<0>(curr) + dY[i];
		int x = get<1>(curr) + dX[i];
		if (CanGo(y,x))
		{
			if (map[y][x] == 0)
			{
				return true;
			}
		}
	}
	return false;
}

int Simulate(vector<vector<int>>& map)
{
	int cleancnt = 0;
	queue<Tuple> robot;
	robot.push(make_tuple(r,c,d));
	while (!robot.empty())
	{

		Tuple curr = robot.front();
		int y = get<0>(curr);
		int x = get<1>(curr);
		int dist = get<2>(curr);
		if (map[y][x] == 0)
		{
			cleancnt++;
			map[y][x] = -1;
		}
		robot.pop();
		if (CheckNotClean(map, curr))
		{
			bool bIsMoved = false;
			for (int i = 0; i < 4; i++)
			{
				if (bIsMoved) break;
				dist = (dist + 3) % 4;
				switch (dist)
				{
				case 0:
					if (CanGo(y - 1, x))
					{
						if (map[y - 1][x] == 0)
						{
							bIsMoved = true;
							robot.push(make_tuple(y - 1, x, dist));
						}
					}
					break;
				case 1:
					if (CanGo(y, x + 1))
					{
						if (map[y][x + 1] == 0)
						{
							bIsMoved = true;
							robot.push(make_tuple(y, x + 1, dist));
						}
					}
					break;
				case 2:
					if (CanGo(y + 1, x))
					{
						if (map[y + 1][x] == 0)
						{
							bIsMoved = true;
							robot.push(make_tuple(y + 1, x, dist));
						}
					}
					break;
				case 3:
					if (CanGo(y, x - 1))
					{
						if (map[y][x - 1] == 0)
						{
							bIsMoved = true;
							robot.push(make_tuple(y, x - 1, dist));
						}
					}
					break;
				}
			}
		}
		else
		{
			switch (dist)
			{
			case 0:
				if (CanGo(y + 1, x))
				{
					if(map[y + 1][x] != 1)
						robot.push(make_tuple(y + 1, x,  dist));
					else
						return cleancnt;
				}
				else
				{
					return cleancnt;
				}
				break;
			case 1:
				if (CanGo(y, x - 1))
				{
					if(map[y][x - 1] != 1)
						robot.push(make_tuple(y, x - 1, dist));
					else
						return cleancnt;
				}
				else
				{
					return cleancnt;
				}
				break;
			case 2:
				if (CanGo(y - 1, x))
				{
					if(map[y - 1][x] != 1)
						robot.push(make_tuple(y - 1, x,  dist));
					else
						return cleancnt;
				}
				else
				{
					return cleancnt;
				}
				break;
			case 3:
				if (CanGo(y, x + 1))
				{
					if(map[y][x + 1] != 1)
						robot.push(make_tuple(y, x + 1, dist));
					else
						return cleancnt;
				}
				else
				{
					return cleancnt;
				}
				break;
			}
		}
	}
	return cleancnt;
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