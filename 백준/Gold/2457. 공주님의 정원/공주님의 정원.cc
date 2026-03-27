#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;
int N;

int SelectFlower(const vector<P>& flower, int current, int count, int index)
{
	if (current >= 1201) return count;
	int endDay = current;
	int nextId = 0;
	for (int i = index + 1; i < N; i++)
	{
		if (flower[i].first > current) break;
		if (flower[i].second > endDay)
		{
			nextId = i;
			endDay = flower[i].second;
		}
	}
	if (nextId == index) return 0;
	return SelectFlower(flower, endDay, count + 1, nextId);
}

// 3월 1일부터 11월 30일까지는 꽃이 한 가지 이상 피어 있어야함.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<P> flower(N);
	for (int i = 0; i < N; i++)
	{
		int startMonth, startDay, endMonth, endDay;
		cin >> startMonth >> startDay >> endMonth >> endDay;
		flower[i] = { startMonth * 100 + startDay, endMonth * 100 + endDay };
	}
	sort(flower.begin(), flower.end());
	cout << SelectFlower(flower, 301, 0, -1);
	return 0;
}