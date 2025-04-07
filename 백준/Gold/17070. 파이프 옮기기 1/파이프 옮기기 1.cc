#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

int N;
int home[17][17]; // 0번째 포함 안함
int way[17][17][3]; // 0번째가 가로, 1번째가 대각, 2번째가 세로
int dp()
{
	way[1][2][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (home[i][j]) continue;
			way[i][j][0] += way[i][j - 1][1] + way[i][j - 1][0];
			way[i][j][2] += way[i - 1][j][1] + way[i - 1][j][2];
			if (!home[i - 1][j] && !home[i][j - 1])
			{
				way[i][j][1] += way[i - 1][j - 1][0] + way[i - 1][j - 1][2] + way[i - 1][j - 1][1];
			}
		}
	}
	return (way[N][N][0] + way[N][N][1] + way[N][N][2]);
}

/*
int dfs()
{
	int arrives = 0;
	stack<pair<int,int>> st;
	stack<int> saveMove;
	st.push(make_pair(1, 2));
	saveMove.push(0);
	while (!st.empty())
	{
		pair<int, int> curr = st.top();
		int currMove = saveMove.top();
		st.pop();
		saveMove.pop();
		// 목적지 도달 시
		if (curr.first == N && curr.second == N)
		{
			arrives++;
			continue;
		}
		// 파이프 움직임
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
				if (currMove == 2 || (curr.second + 1 > N) || home[curr.first][curr.second + 1])
					break;
				else
				{
					st.push(make_pair(curr.first, curr.second + 1));
					saveMove.push(0);
				}
				break;
			case 1:
				if ((curr.first + 1 > N || curr.second + 1 > N) 
					|| home[curr.first + 1][curr.second + 1] 
					|| home[curr.first][curr.second + 1] 
					|| home[curr.first + 1][curr.second])
					break;
				else
				{
					st.push(make_pair(curr.first + 1, curr.second + 1));
					saveMove.push(1);
				}
				break;
			case 2:
				if ((currMove == 0|| curr.first + 1 > N) || home[curr.first + 1][curr.second])
					break;
				else
				{
					st.push(make_pair(curr.first + 1, curr.second));
					saveMove.push(2);
				}
				break;
			default:
				break;
			}
		}
	}
	return arrives;
}
*/
/*
int bfs()
{
	int arrives = 0;
	queue<pair<int, int>> q;
	queue<int> saveMove;
	q.push(make_pair(1, 2));
	saveMove.push(0);
	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		int currMove = saveMove.front();
		q.pop();
		saveMove.pop();
		// 목적지 도달 시
		if (curr.first == N && curr.second == N)
		{
			arrives++;
			continue;
		}
		// 파이프 움직임
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
				if (currMove == 2 || (curr.second + 1 > N) || home[curr.first][curr.second + 1])
					break;
				else
				{
					q.push(make_pair(curr.first, curr.second + 1));
					saveMove.push(0);
				}
				break;
			case 1:
				if ((curr.first + 1 > N || curr.second + 1 > N)
					|| home[curr.first + 1][curr.second + 1]
					|| home[curr.first][curr.second + 1]
					|| home[curr.first + 1][curr.second])
					break;
				else
				{
					q.push(make_pair(curr.first + 1, curr.second + 1));
					saveMove.push(1);
				}
				break;
			case 2:
				if ((currMove == 0 || curr.first + 1 > N) || home[curr.first + 1][curr.second])
					break;
				else
				{
					q.push(make_pair(curr.first + 1, curr.second));
					saveMove.push(2);
				}
				break;
			default:
				break;
			}
		}
	}
	return arrives;
}
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> home[i][j];

	// cout << dfs();
	cout << dp();


	return 0;
}