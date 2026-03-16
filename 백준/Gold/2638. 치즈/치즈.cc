#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;

#define P pair<int,int>

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int cnt = 0;
vector<vector<bool>> OutsideSearch(vector<vector<int>>& map)
{
	vector<vector<bool>> visited(M, vector<bool>(N, false));
	queue<P> Q;
	Q.push({ 0, 0 });
	visited[0][0] = true;
	while (!Q.empty())
	{
		P curr = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = curr.first + dx[i];
			int y = curr.second + dy[i];
			if (x < 0 || y < 0 || x >= M || y >= N) continue;
			if (!visited[x][y] && map[x][y] == 0)
			{
				visited[x][y] = true;
				Q.push({ x, y });
			}
		}
	}
	return visited;
}

void MapUpdate(vector<vector<int>>& map, queue<P>& cheese)
{
	if (cheese.empty()) return;
	vector<vector<bool>> visited;
	visited = OutsideSearch(map);
	queue<P> Q;
	while (!cheese.empty())
	{
		int outcount = 0;
		P curr = cheese.front();
		cheese.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = curr.first + dx[i];
			int y = curr.second + dy[i];
			if (x < 0 || y < 0 || x >= M || y >= N) continue;
			if (map[x][y] == 0 && visited[x][y])
			{
				outcount++;
			}
		}
		if (outcount < 2)
		{
			Q.push({ curr.first, curr.second });
		}
		else
		{
			map[curr.first][curr.second] = 0;
		}
	}
	cnt++;
	MapUpdate(map, Q);
}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<vector<int>> map(M, vector<int>(N, 0));
	queue<P> cheese;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[x][y];
			if (map[x][y] == 1) cheese.push({ x, y });
		}
	}
	MapUpdate(map, cheese);

	cout << cnt;

	return 0;
}