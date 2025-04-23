#include<iostream>
using namespace std;

int N, A[1000];
int Rdp[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int maxNum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		Rdp[i] = 1;
		for (int j = N - 1; j >= i; j--)
		{
			if (A[i] > A[j])
			{
				Rdp[i] = max(Rdp[i], Rdp[j] + 1);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (answer < Rdp[i]) answer = Rdp[i];
	}
	cout << answer;
	return 0;
}