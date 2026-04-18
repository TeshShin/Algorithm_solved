#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

constexpr int MAX = 500'001;
int parent[MAX];

void Init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
}

int Find(int key)
{
	if (parent[key] == key) return key;
	return Find(parent[key]);
}

bool Union(int a, int b)
{
	int rootA = Find(a);
	int rootB = Find(b);
	if (rootA == rootB) return false;

	if (rootA < rootB)
	{
		parent[rootB] = rootA;
	}
	else
	{
		parent[rootA] = rootB;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	Init(n);
	for (int i = 1; i <= m; i++)
	{
		int from, to;
		cin >> from >> to;
		if (!Union(from, to))
		{
			cout << i;
			return 0;
		}
	}
	cout << '0';

	return 0;
}