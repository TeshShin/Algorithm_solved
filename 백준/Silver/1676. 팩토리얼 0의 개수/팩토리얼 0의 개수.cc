#include<iostream>

using namespace std;

int main() {
	int N, zerocheck = 0;
	cin >> N;
	for (int i = 5; i <= N; i *= 5) {
		zerocheck += (N / i);
	}
	cout << zerocheck;
}