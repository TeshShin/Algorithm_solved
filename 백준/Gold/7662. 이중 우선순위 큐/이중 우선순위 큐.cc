#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		priority_queue<int, vector<int>, less<int>> pq_max;
		priority_queue<int, vector<int>, greater<int>> pq_min;
		map<int, int> cntmp;
		int N;
		cin >> N;
		while (N--) {
			char command;
			int num;
			cin >> command;
			cin >> num;
			if (command == 'I') {
				pq_max.push(num);
				pq_min.push(num);
				cntmp[num]++;
			}
			else if (num == 1 && !pq_max.empty()){
				cntmp[pq_max.top()]--;
				pq_max.pop();
			}
			else if(num == -1 && !pq_min.empty()){
				cntmp[pq_min.top()]--;
				pq_min.pop();
			}
			// 원소가 유효하지 않으면 빼줘야한다.
			while (!pq_max.empty() && !cntmp[pq_max.top()]) pq_max.pop();
			while (!pq_min.empty() && !cntmp[pq_min.top()]) pq_min.pop();
		}
		if (pq_min.empty() || pq_max.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << pq_max.top() << " " << pq_min.top() << '\n';
		}
	}
	return 0;
}