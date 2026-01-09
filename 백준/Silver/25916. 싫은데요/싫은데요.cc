#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	vector<int> holes(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> holes[i];
	}
	int start = 0;
	int max = 0;
	int curr = 0;
	for (int end = 0; end < N; end++)
	{
		if (holes[end] > M) // 해당 구멍이 M보다 크면 다음 것부터 초기화
		{
			start = end + 1;
			curr = 0;
			continue;
		}
		curr += holes[end];
		if (curr == M) // 부피랑 현재까지의 구멍 크기가 같으면 걍 최대라 끝
		{
			max = curr;
			break;
		}
		while (curr > M) // 현재까지의 구멍 크기의 합이 부피보다 크면 맨 앞부터 구멍을 작아질 때까지 제외
		{
			curr -= holes[start];
			start++;
		}

		if (max < curr) // 현재까지의 구멍 크기의 합이 최대보다 크면 업데이트
		{
			max = curr;
		}
	}

	cout << max;
}