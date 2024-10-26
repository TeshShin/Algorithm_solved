#include<iostream>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	pair<int, int> timetable[100001];
	for (int i = 0; i < N; i++) {
		cin >> timetable[i].first >> timetable[i].second;
	}
	sort(timetable, timetable + N, compare);
	//check
	//for (int i = 0; i < N; i++) {
	//	cout << timetable[i].first << " " << timetable[i].second << "\n";
	//}
	int end = timetable[0].second;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (timetable[i].first >= end) {
			cnt++;
			end = timetable[i].second;
		}
	}
	cout << cnt;
}