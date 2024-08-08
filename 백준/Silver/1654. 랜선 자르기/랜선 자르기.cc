#include<iostream>

using namespace std;


/*
unsigned K, N;
unsigned lan[10000], minLan, maxLan; // --> (ll)2147483648 = (int)-2147483648

void solve()
{
	unsigned L, R, mid;


	L = 1, R = maxLan;
	while (L <= R) { // 방법 3에서는 while의 종료 조건 달라짐
		mid = (L + R) / 2;

		unsigned cnt = 0;
		for (int i = 0; i < K && cnt < N; ++i) cnt += lan[i] / mid;

		if (cnt < N) R = mid - 1;
		else L = mid + 1;
	}
	// 탐색 끝난 이후 L, R의 관계도 달라짐 (방법 1: L == R == mid, 방법 3: L > R)
	cout << --L; // L > R, 마지막 mid는 계산 안 된 상태
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
*/

// 아래는 재귀 방식인데 시간 초과임... 왜지??
// ==>  해결함 재귀함수에 return 안붙여서 그럼
unsigned parametricSearch(unsigned start, unsigned end);

unsigned k, n;

unsigned line[10000], minLen, maxLen;

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



unsigned parametricSearch(unsigned start, unsigned end) {
	if (start > end) {
		return start - 1;
	}
	unsigned mid = (start + end) / 2;

	unsigned cnt = 0;
	for (int i = 0; i < k && cnt < n; ++i) cnt += line[i] / mid;

	if (cnt >= n){
		return parametricSearch(mid + 1, end);
	}
	else {
		return parametricSearch(start, mid - 1);
	}

}
