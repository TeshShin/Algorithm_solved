#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int homeLength = 0;
int chickenLength = 0;
int input;
int home[101][2];
int chicken[14][2];
int walk[101][14];

vector<int> selecthome;
int ans = 50 * 50 * 100;

void backtracking(int depth, int start)
{
	if (depth == M)
	{
		int total = 0;
		for (int i = 1; i <= homeLength; i++)
		{
			int min = 50 * 2;
			for (int j = 0; j < M; j++)
			{
				min = min > walk[i][selecthome[j]] ? walk[i][selecthome[j]] : min;
			}
			total += min;
		}
		ans = ans > total ? total : ans;
	}
	else
	{
		for (int i = start; i <= chickenLength; i++)
		{
			selecthome.push_back(i);
			backtracking(depth + 1, i + 1);
			selecthome.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> input;
			if (input == 1)
			{
				homeLength++;
				home[homeLength][0] = i;
				home[homeLength][1] = j;
			}
			else if (input == 2)
			{
				chickenLength++;
				chicken[chickenLength][0] = i;
				chicken[chickenLength][1] = j;
			}
		}
	}
	for (int i = 1; i <= homeLength; i++)
	{
		for (int j = 1; j <= chickenLength; j++)
		{
			walk[i][j] = abs(home[i][0] - chicken[j][0]) + abs(home[i][1] - chicken[j][1]);
		}
	}
	backtracking(0, 1);
	cout << ans;
	return 0;
}