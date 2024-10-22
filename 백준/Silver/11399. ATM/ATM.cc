#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
	int N;
	int Pi;

	cin >> N;
	vector<int> line(N); // (0, N)으로 초기화도 됨
	
	for (int i = 0; i < N; i++) {
		cin >> line[i];
	}

	sort(line.begin(), line.end());

	int temp = 0;
	int total = 0;
	for (int i = 0; i < N; i++) {
		temp += line[i];
		total += temp;
	}
	cout << total;

	return 0;
}