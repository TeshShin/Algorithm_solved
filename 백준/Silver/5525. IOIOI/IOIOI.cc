#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, length = 1;
	cin >> N >> M;
	string p = "I";
	for (int i = 0; i < N; i++) {
		p += "OI";
		length += 2;
	}
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < M; i++) {
		if (s[i] == 'I') {
			if (s.substr(i, length) == p) {
				count++;
			}
		}
	}
	cout << count;
	return 0;
}