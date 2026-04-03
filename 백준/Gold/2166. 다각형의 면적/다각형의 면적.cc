#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair <ll, ll>;

ll CalcExtent(const P& a, const P& b)
{
	return a.first * b.second - a.second * b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vector<P> Points(N);
	ll Sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> Points[i].first >> Points[i].second;
	}
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
		{
			Sum += CalcExtent(Points[i], Points[0]);
		}
		else
		{
			Sum += CalcExtent(Points[i], Points[i + 1]);
		}
	}
	double Extent = 0.5 * abs(Sum);
	cout << fixed;
	cout.precision(1);
	cout << Extent;
	return 0;
}