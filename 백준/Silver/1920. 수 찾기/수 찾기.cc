#include<iostream>
#include<algorithm>
using namespace std;

int num[100001];

int findnum(int* num, int target, int first, int last) {
	int mid = (first + last) / 2;
	if (first > last) {
		return 0;
	}
	else {
		if (num[mid] == target) {
			return 1;
		}
		else if (num[mid] < target) {
			return findnum(num, target, mid + 1, last);
		}
		else if (num[mid] > target) {
			return findnum(num, target, first, mid - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, N, num1;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num[i];
	}
	sort(num, num + M);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num1;
		cout << findnum(num, num1, 0, M - 1) << '\n';
	}
	return 0;
}
