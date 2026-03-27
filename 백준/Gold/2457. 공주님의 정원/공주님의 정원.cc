#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using P = pair<int, int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<P> flowers(n);

	for (int i = 0; i < n; i++)
	{
		int startMonth, startDay, endMonth, endDay;
		cin >> startMonth >> startDay >> endMonth >> endDay;

		int start = startMonth * 100 + startDay;
		int end = endMonth * 100 + endDay;

		flowers[i] = { start, end };
	}

	sort(flowers.begin(), flowers.end());

	int current = 301;
	int index = 0;
	int answer = 0;

	while (current < 1201)
	{
		int maxEnd = current;

		while (index < n && flowers[index].first <= current)
		{
			maxEnd = max(maxEnd, flowers[index].second);
			index++;
		}

		if (maxEnd == current)
		{
			cout << 0;
			return 0;
		}

		current = maxEnd;
		answer++;
	}

	cout << answer;
	return 0;
}