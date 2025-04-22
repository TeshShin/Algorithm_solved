#include<iostream>
using namespace std;

int N;
long long B;

int A[5][5];
int ans[5][5];

// 배열의 원소는 이미 콜 바이 레퍼런스
void calculateMat(int m[][5], int A[][5])
{
	int result[5][5];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				result[i][j] += (m[k][j] * A[i][k]);
				result[i][j] %= 1000;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			m[i][j] = result[i][j];
		}
	}
}

// 지수법칙을 이용해 큰 수의 지수를 나누어, 작은 지수들의 값부터 구해 점차 큰 지수의 값을 차곡차곡 쌓아 구한다.
void powMat(long long b)
{

	while (b > 0)
	{
		// 지수가 홀수이면 정답행렬에 A 행렬을 곱하면 된다.
		// 즉, 정답행렬과 A행렬이 곱해지는 경우는 
		// 1. 초기의 b가 홀수일 때
		// 2. b가 1까지 나누어졌을 때 뿐이다.
		// 초기의 b가 홀수라면, 지수법칙에 의해 A행렬이 한번 더 곱해져야하므로 위의 경우와 알맞다.
		if (b % 2 == 1)
		{
			calculateMat(ans, A);
		}
		// b가 만약 5라면,
		// b : 5 -> 2 -> 1 이지만,
		// A : A^2->A^4 -> A^6 가 된다. A^6이 ans에 들어갈 일은 없다.
		calculateMat(A, A);
		b /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
		// 단위행렬로 미리 만들어, 나중에 A행렬을 복사할 수 있도록 한다.
		ans[i][i] = 1;
	}
	powMat(B);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}