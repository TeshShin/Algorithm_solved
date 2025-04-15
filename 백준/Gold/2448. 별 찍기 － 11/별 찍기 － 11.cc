#include<iostream>
using namespace std;

int N; // 3 * 2^k (3, 6, 12 ...)(0<= k <= 10)
char star[3072][6144]; // 세로 = N, 가로 = 2N - 1

void printstar(int y, int x, int n)
{
	if (n == 3)
	{
		star[y][x] = '*';

		star[y + 1][x - 1] = '*';
		star[y + 1][x + 1] = '*';

		for(int i = 0; i < 5; i++)
			star[y + 2][x - 2 + i] = '*';
	}
	else
	{
		printstar(y, x, n / 2);
		printstar(y + n / 2, x - n / 2, n / 2);
		printstar(y + n / 2, x + n / 2, n / 2);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
		{
			star[i][j] = ' ';
		}
	}
	printstar(0, N - 1, N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
		{
			cout << star[i][j];
		}
		cout << '\n';
	}
	return 0;
}