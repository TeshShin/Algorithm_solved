#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long N, M;

bool check(vector<long long> tree, long long mid) {
	long long total = 0;
	for (long long i = 0; i < N; i++) {
		if (tree[i] > mid) {
			total += tree[i] - mid;
		}
	}
	if (total >= M) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vector<long long> tree(N, 0);
	for (long long i = 0; i < N; i++) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	long long left = tree[N - 1] - M;
	long long right = tree[N - 1];

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (check(tree, mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	
	cout << left - 1;
	return 0;
}