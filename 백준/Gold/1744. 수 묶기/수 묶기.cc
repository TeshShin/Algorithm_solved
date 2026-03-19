#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;

bool compare(int i, int j)
{
	return i > j;
}

bool PlusIsBetter(int i, int j)
{
	return (i + j) > (i * j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> positive;
	vector<int> negative;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (input > 0)
			positive.push_back(input);
		else
			negative.push_back(input);
	}
	sort(positive.begin(), positive.end(), compare);
	sort(negative.begin(), negative.end());
	int answer = 0;
	for (int i = 0; i < positive.size(); i++)
	{
		if ((i + 1) >= positive.size() || PlusIsBetter(positive[i], positive[i + 1]))
		{
			answer += positive[i];
		}
		else
		{
			answer += positive[i] * positive[i + 1];
			i++;
		}
	}
	for (int i = 0; i < negative.size(); i++)
	{
		if ((i + 1) >= negative.size() || PlusIsBetter(negative[i], negative[i + 1]))
		{
			answer += negative[i];
		}
		else
		{
			answer += negative[i] * negative[i + 1];
			i++;
		}
	}

	cout << answer;
	return 0;
}