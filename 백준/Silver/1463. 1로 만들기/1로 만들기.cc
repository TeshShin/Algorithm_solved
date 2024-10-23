#include<iostream>
using namespace std;



int main() {
	int N;
	cin >> N;
	int table[1000001];
	table[1] = 0, table[2] = 1, table[3] = 1;
	for (int i = 4; i <= N; i++) {
		int temp = table[i - 1] + 1; // 1 빼기로 + 1하고 이전 꺼 최소 횟수로

		if (i % 3 == 0) temp = min(temp, table[i / 3] + 1); // 3나눠 떨어지는 횟수
		if (i % 2 == 0) temp = min(temp, table[i / 2] + 1); // 2나눠 떨어지는 횟수
		table[i] = temp;
	}
	cout << table[N];
}