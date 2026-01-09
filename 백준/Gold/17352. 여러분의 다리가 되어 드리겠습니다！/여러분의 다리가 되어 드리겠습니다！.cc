#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, Edge;
int parent[300001];

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;

	(a > b) ? parent[a] = b : parent[b] = a; 
}

bool IsUnion(int a, int b)
{
	a = Find(a);
	b = Find(b);
	return a == b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	Edge = N - 2;
	int From, To;
	while (Edge--)
	{
		cin >> From >> To;
		Union(From, To);
	}
	for (int i = 2; i <= N; i++)
	{
		if (!IsUnion(1, i))
		{
			cout << "1 " << i;
			break;
		}
	}
}