#include<iostream>
#include<algorithm>
using namespace std;

int ary[1000001];
pair<int, int> save[1000001];

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
		save[i].first = ary[i];
		save[i].second = i;
	}
	sort(save, save + N, compare);
	int numbering = 0;
	ary[save[0].second] = numbering;
	for (int i = 1; i < N; i++) {
		if (save[i].first == save[i - 1].first) {
			ary[save[i].second] = numbering;
		}
		else {
			ary[save[i].second] = ++numbering;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ary[i] << " ";
	}
	
	return 0;
}