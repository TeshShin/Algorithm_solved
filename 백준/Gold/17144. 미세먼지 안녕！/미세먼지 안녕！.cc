#include<iostream>
#include<vector>
using namespace std;


int R, C, T;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> freshPos;
vector<vector<int>> Splash(vector<vector<int>>& graph)
{
	vector<vector<int>> newGraph(R, vector<int>(C, 0));
	newGraph[freshPos[0].first][freshPos[0].second] = -1;
	newGraph[freshPos[1].first][freshPos[1].second] = -1;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (graph[i][j] == 0 || graph[i][j] == -1) continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int y = i + dy[k];
				int x = j + dx[k];
				if (0 <= y && y < R && 0 <= x && x < C)
				{
					if (newGraph[y][x] == -1) continue;
					newGraph[y][x] += graph[i][j] / 5;
					cnt++;
				}
			}
			newGraph[i][j] += graph[i][j] - (graph[i][j] / 5) * cnt;
		}
	}
	return newGraph;
}
void FreshAir(vector<vector<int>>& graph)
{
	int firstY = freshPos[0].first;
	int firstX = freshPos[0].second;
	while (firstY)
	{
		graph[firstY][firstX] = graph[firstY - 1][firstX];
		firstY--;
	}
	while (firstX < C - 1)
	{
		graph[firstY][firstX] = graph[firstY][firstX + 1];
		firstX++;
	}
	
	while (firstY < freshPos[0].first)
	{
		graph[firstY][firstX] = graph[firstY + 1][firstX];
		firstY++;
	}
	while (firstX)
	{
		graph[firstY][firstX] = graph[firstY][firstX - 1];
		firstX--;
	}
	int secondY = freshPos[1].first;
	int secondX = freshPos[1].second;
	
	while (secondY < R - 1)
	{
		graph[secondY][secondX] = graph[secondY + 1][secondX];
		secondY++;
	}
	
	while (secondX < C - 1)
	{
		graph[secondY][secondX] = graph[secondY][secondX + 1];
		secondX++;
	}
	while (secondY > freshPos[1].first)
	{
		graph[secondY][secondX] = graph[secondY - 1][secondX];
		secondY--;
	}
	while (secondX)
	{
		graph[secondY][secondX] = graph[secondY][secondX - 1];
		secondX--;
	}
	
	graph[freshPos[0].first][freshPos[0].second] = -1;
	graph[freshPos[1].first][freshPos[1].second] = -1;
	if (C > 1)
	{
		graph[freshPos[0].first][freshPos[0].second + 1] = 0;
		graph[freshPos[1].first][freshPos[1].second + 1] = 0;
	}
}

int DustCount(vector<vector<int>>& graph)
{
	int cnt = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (graph[i][j] == -1) continue;
			cnt += graph[i][j];
		}
	}
	return cnt;
}
// 디버그용
void ShowGraph(vector<vector<int>>& graph)
{
	cout << "그래프 출력" << '\n';
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> T;
	vector<vector<int>> graph(R, vector<int>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == -1)
			{
				freshPos.push_back({ i,j });
			}
		}
	}
	while (T--)
	{
		graph = Splash(graph);
		//ShowGraph(graph);
		FreshAir(graph);
		//ShowGraph(graph);
	}
	cout << DustCount(graph);
	return 0;
}