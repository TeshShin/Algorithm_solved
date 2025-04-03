#include<iostream>
#include<deque>
using namespace std;

int N, K;
int visit[100001];

int bfs01()
{
	deque<int> d;
	d.push_back(N);
	while (!d.empty())
	{
		int current = d.front();
		d.pop_front();
		if (current == K) return visit[K];
		
		int move = current * 2;
		if (0 <= move && move < 100001 && visit[move] > visit[current])
		{
			visit[move] = visit[current];
			d.push_front(move);
		}
		move = current - 1;
		if (0 <= move && move < 100001 && visit[move] > visit[current] + 1)
		{
			visit[move] = visit[current] + 1;
			d.push_back(move);
		}
		move = current + 1;
		if (0 <= move && move < 100001 && visit[move] > visit[current] + 1)
		{
			visit[move] = visit[current] + 1;
			d.push_back(move);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i <= 100000; i++)
	{
		visit[i] = 100001;
	}
	cin >> N >> K;
	visit[N] = 0;
	cout << bfs01();
	return 0;
}