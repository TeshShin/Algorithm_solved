#include<iostream>
#include<stack>

using namespace std;

int R, C;
char table[21][21];
bool visited[26];
int answer = 0;
int D[4] = { -1, 1, 0, 0 };
struct Table
{
	int row;
	int col;
	int depth;
};
void dfs(int row, int col, int depth)
{
	if (answer < depth) answer = depth;

	for(int i = 0; i < 4; i++)
	{
		int newrow = row + D[i];
		int newcol = col + D[3 - i];
		if (newcol >= 0 && newrow >= 0 && newcol < C && newrow < R)
		{
			if (!visited[table[newrow][newcol] - 'A'])
			{
				visited[table[newrow][newcol] - 'A'] = true;
				dfs(newrow, newcol, depth + 1);
				visited[table[newrow][newcol] - 'A'] = false;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> table[i][j];
		}
	}
	visited[table[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << answer;
	return 0;
}