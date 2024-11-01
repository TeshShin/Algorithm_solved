#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int T, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		map<string, int> wear;
		for (int j = 0; j < N; j++) {
			string parts;
			cin >> parts >> parts;
			wear[parts]++;
		}
		int total = 1;
		for (pair<string, int> p : wear) {
			total *= p.second + 1;
		}
		cout << total - 1<< '\n';
	}
	return 0;
}