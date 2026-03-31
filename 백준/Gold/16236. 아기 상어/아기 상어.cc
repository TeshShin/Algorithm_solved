#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

using T = tuple<int, int, int>;
using P = pair<int, int>;
int d[4] = { 1,-1,0,0 };
int N;
bool CanGo(int a, int b)
{
	return a >= 0 && b >= 0 && a < N && b < N;
}

vector<T> BFS(vector<vector<int>>& map, int startRow, int startCol, int babyShark, int time)
{
	queue<T> q;
	vector<vector<bool>> visited(N, vector<bool>(N, 0));
	vector<T> fishes;
	q.push({ time, startRow, startCol });
	
	while (!q.empty())
	{
		T curr = q.front();
		int deltaTime = get<0>(curr);
		int row = get<1>(curr);
		int col = get<2>(curr);
		q.pop();
		if (visited[row][col]) continue;
		visited[row][col] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextRow = row + d[i];
			int nextCol = col + d[3 - i];
			if (CanGo(nextRow, nextCol) && !visited[nextRow][nextCol])
			{

				if (map[nextRow][nextCol] == 0 || map[nextRow][nextCol] == babyShark)
				{
					q.push({ deltaTime + 1, nextRow, nextCol  });
				}
				else if (map[nextRow][nextCol] < babyShark)
				{
					fishes.push_back({ deltaTime + 1, nextRow, nextCol });
					visited[nextRow][nextCol] = true;
				}
			}
		}
	}
	return fishes;
}

bool compare(T a, T b)
{
	int aCost = get<0>(a), aRow = get<1>(a), aCol = get<2>(a);
	int bCost = get<0>(b), bRow = get<1>(b), bCol = get<2>(b);
	if (aCost == bCost)
	{
		if (aRow == bRow)	return aCol < bCol;
		else return aRow < bRow;
	}
	else return aCost < bCost;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int babyShark = 2;
	cin >> N;
	vector<vector<int>> map(N, vector<int>(N, 0));
	int startRow, startCol;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				startRow = i;
				startCol = j;
				map[i][j] = 0;
			}

		}
	}
	vector<T> fishes(1);
	int eatTimes = 0;
	int deltaTime = 0;
	while (!fishes.empty())
	{
		if (eatTimes == babyShark)
		{
			babyShark++;
			eatTimes = 0;
		}
		fishes = BFS(map, startRow, startCol, babyShark, deltaTime);
		if (fishes.empty()) break;
		sort(fishes.begin(), fishes.end(), compare);
		deltaTime = get<0>(fishes[0]);
		startRow = get<1>(fishes[0]);
		startCol = get<2>(fishes[0]);
		map[startRow][startCol] = 0;
		eatTimes++;
	}
	cout << deltaTime;

	return 0;
}