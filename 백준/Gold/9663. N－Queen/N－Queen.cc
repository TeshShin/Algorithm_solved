#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> table(14, -1);
int cnt = 0;
void NQueen(int depth) // depth는 현재의 행이다.
{
	if (depth == N)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < N; i++) // i는 현재의 열이다.
		{
			if (table[depth] == -1)
			{
				bool canQueen = true;
				for (int row = 0; row < depth; row++)
				{
					if (table[row] == i)
					{
						canQueen = false;
						break;
					}
					else if(abs(depth - row) == abs(i - table[row]))
					{
						canQueen = false;
						break;
					}
				}
				if (canQueen)
				{
					table[depth] = i;
					NQueen(depth + 1);
					table[depth] = -1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	NQueen(0);
	cout << cnt;

	return 0;
}