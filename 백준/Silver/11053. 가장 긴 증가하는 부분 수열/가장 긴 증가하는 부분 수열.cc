#include<iostream>
using namespace std;

int N;
int A[1000];
int DP[1000];
int answer = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		DP[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (A[i] > A[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		answer = max(DP[i], answer);
	}
	
	cout << answer;

	return 0;
}