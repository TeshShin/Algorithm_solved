#include<iostream>

using namespace std;
int box[1025][1025];
int N, M;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int input;
			cin >> input;
			if (j == 1) // 첫 세로 층 쌓기
			{
				box[i][j] = input + box[i - 1][j];
			}
			else if (i == 1) // 첫 가로 층 쌓기
			{
				box[i][j] = input + box[i][j - 1];
			}
			else // 직사각형의 합 채우기
			{
				box[i][j] = input + box[i][j - 1] + box[i - 1][j] - box[i - 1][j - 1];
			}
		}
	}
	while (M--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << box[x2][y2] - box[x1 - 1][y2] - box[x2][y1 - 1] + box[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}