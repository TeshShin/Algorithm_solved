#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int maxSafeArea = 0;
int moving[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> viruspos;

void Virusbfs(vector<vector<int>>& map)
{
	queue<pair<int, int>> virusQ;
	for (pair<int, int> pos : viruspos)
	{
		virusQ.push(pos);
	}
	while (!virusQ.empty())
	{
		int y = virusQ.front().first;
		int x = virusQ.front().second;
		virusQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int newy = y + moving[i];
			int newx = x + moving[3 - i];
			if (newy >= 0 && newy < N && newx >= 0 && newx < M)
			{
				if (map[newy][newx] == 0)
				{
					map[newy][newx] = 1;
					virusQ.push(make_pair(newy, newx));
				}
			}
		}

	}
}
int GetSafeArea(vector<vector<int>>& map)
{
	int safeArea = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				safeArea++;
			}
		}
	}
	return safeArea;
}

void BuildWall(vector<vector<int>>& map, int count)
{
	if (count == 3)
	{
		vector<vector<int>> tempMap = map;
		Virusbfs(tempMap);
		maxSafeArea = max(GetSafeArea(tempMap), maxSafeArea);
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = 1;
					BuildWall(map, count + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) viruspos.push_back(make_pair(i, j));
		}
	}
	BuildWall(map, 0);
	cout << maxSafeArea;
	return 0;
}