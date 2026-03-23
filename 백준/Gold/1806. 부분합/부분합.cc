#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, S;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	vector<int> list(N, 0);
	const int inf = N + 1;
	int answer = inf;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	int start = 0;
	int end = 0;
	int sum = 0;
	while (start < N)
	{
		
		if (sum >= S)
		{
			if (end - start < answer)
				answer = end - start;
			sum -= list[start];
			start++;
		}
		else if (end < N)
		{
			sum += list[end];
			end++;
		}
		else
			break;
	}
	if (answer == inf)
		cout << 0;
	else
		cout << answer;
	return 0;
}