#include<iostream>
using namespace std;


int T, N;
int sticker[100000][2];

void print()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << sticker[j][i] << " ";
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	while (T--)
	{
		
		cin >> N;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> sticker[j][i];
			}
		}
		int maxScore = max(sticker[0][0], sticker[0][1]);
		if (N > 1)
		{
			sticker[1][0] += sticker[0][1];
			sticker[1][1] += sticker[0][0];
			maxScore = max(sticker[1][0], sticker[1][1]);
		}
		for (int j = 2; j < N; j++)
		{
			sticker[j][0] += max(sticker[j - 1][1], sticker[j - 2][1]);
			if (maxScore < sticker[j][0])
			{
				maxScore = sticker[j][0];
			}
			sticker[j][1] += max(sticker[j - 1][0], sticker[j - 2][0]);
			if (maxScore < sticker[j][1])
			{
				maxScore = sticker[j][1];
			}
			
		}
		cout << maxScore << '\n';
	}


	return 0;
}