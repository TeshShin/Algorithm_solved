#include<iostream>
#include<queue>
using namespace std;

int N, K;
int times = 0;
int line[100001];
void HideAndSeek2(int line[])
{
	queue<int> q;
	line[N] = 0;
	q.push(N);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (curr == K) times++;
		int moving;
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
				moving = curr - 1;
				if (0 <= moving && moving <= 100000)
				{
					if (line[moving] >= line[curr] + 1)
					{
						line[moving] = line[curr] + 1;
						q.push(moving);
					}
				}
				break;
			case 1:
				moving = curr + 1;
				if (0 <= moving && moving <= 100000)
				{
					if (line[moving] >= line[curr] + 1)
					{
						line[moving] = line[curr] + 1;
						q.push(moving);
					}
				}
				break;
			case 2:
				moving = curr * 2;
				if (0 <= moving && moving <= 100000)
				{
					if (line[moving] >= line[curr] + 1)
					{
						line[moving] = line[curr] + 1;
						q.push(moving);
					}
				}
				break;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
	{
		line[i] = 100002;
	}
	HideAndSeek2(line);
	cout << line[K] << '\n' <<times;
	return 0;
}