#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int inf = 2'000'000'000;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int> input(N);
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	int left = 0;
	int right = N - 1;
	int minDiff = inf;
	int minLeft = 0;
	int minRight = N - 1;
	while (left < right)
	{
		int sum = input[left] + input[right];
		int diff = abs(sum);
		if (diff < minDiff)
		{
			minDiff = diff;
			minLeft = left;
			minRight = right;
		}
		if (sum == 0)
		{
			break;
		}
		else if (sum < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	cout << input[minLeft] << ' ' << input[minRight];

	return 0;
}