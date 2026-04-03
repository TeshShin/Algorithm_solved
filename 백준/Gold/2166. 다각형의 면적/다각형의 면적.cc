#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair <ll, ll>;

double CalcExtent(const P& a, const P& b)
{
	return a.first * b.second - a.second * b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vector<P> points(N);
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> points[i].first >> points[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		int next = (i + 1) % N;
		sum += CalcExtent(points[i], points[next]);
	}
	double extent = 0.5 * abs(sum);
	cout << fixed;
	cout.precision(1);
	cout << extent;
	return 0;
}