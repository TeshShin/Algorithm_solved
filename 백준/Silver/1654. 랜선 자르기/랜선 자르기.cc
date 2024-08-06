#include<iostream>

using namespace std;
unsigned K, N;
unsigned lan[10000], minLan, maxLan; // --> (ll)2147483648 = (int)-2147483648

void solve()
{
	unsigned L, R, mid;


	// 방법 1:  Y Y Y Y Y [Y] N N N N
	// success
	L = 1, R = maxLan;
	while (L != R) {
		mid = (L + R + 1) / 2;  // mid = (L+R)/2 로 계산할 경우 - 시간 초과
		// Y Y Y Y Y N N N 꼴이기 때문에 mid = ceil((L+R)/2) = (L+R+1)/2 여야 함

		unsigned cnt = 0;
		for (int i = 0; i < K && cnt < N; ++i) cnt += lan[i] / mid;

		if (cnt < N) R = mid - 1;
		else L = mid;
	}
	cout << L; // L = R = mid
	cout << '\n';
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> K >> N;

	for (int i = 0; i < K; ++i) { // ~ 10^4
		cin >> lan[i];
		if (i == 0) minLan = lan[i];
		if (lan[i] > maxLan) maxLan = lan[i];
		if (lan[i] < minLan) minLan = lan[i];
	}

	solve();

	return 0;
}



/*
long long parametricSearch(long long start, long long end);

long long k, n;

long long line[10000], minLen, maxLen;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> line[i];
		if (i == 0) minLen = line[i];
		if (line[i] > maxLen) maxLen = line[i];
		if (line[i] < minLen) minLen = line[i];
	}

	cout << parametricSearch(1, maxLen);


	return 0;
}



long long parametricSearch(long long start, long long end) {
	if (start > end) {
		return start - 1;
	}
	long long mid = (start + end) / 2;

	long long cnt = 0;
	for (int i = 0; i < k && cnt < n; ++i) cnt += line[i] / mid;

	if (cnt >= n){
		parametricSearch(mid + 1, end);
	}
	else {
		parametricSearch(start, mid - 1);
	}

}
*/