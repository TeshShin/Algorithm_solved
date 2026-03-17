#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

int N, M, L;
vector<int> canDist;
int Check(vector<int>& dist, int mid)
{
	int restcnt = 0;
	for (auto d : dist)
	{
		int check = (d - 1) / mid;
		if (check < 0) continue;
		restcnt += check;
	}
	return restcnt;
}

void BinarySearch(vector<int>& dist, int left, int right)
{
	if (left > right) return;
	int mid = (left + right) / 2;

	if (Check(dist, mid) <= M)
	{
		canDist.push_back(mid);
		BinarySearch(dist, left, mid - 1);
	}
	else
	{
		BinarySearch(dist, mid + 1, right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> L;

	vector<int> rest;
	rest.push_back(0);
	rest.push_back(L);
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		rest.push_back(input);
	}
	sort(rest.begin(), rest.end());
	vector<int> dist;
	for (int i = 0; i <= N; i++)
	{
		dist.push_back(abs(rest[i] - rest[i + 1]));
	}
	sort(dist.begin(), dist.end());
	BinarySearch(dist, 1, dist[N]);
	sort(canDist.begin(), canDist.end());
	cout << canDist[0];
	return 0;
}