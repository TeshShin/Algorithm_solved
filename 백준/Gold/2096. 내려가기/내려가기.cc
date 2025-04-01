#include<iostream>
#include<algorithm>
using namespace std;

int dpmin[3];
int dpmax[3];

int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int input[3];
	cin >> N;
	cin >> dpmin[0];
	cin >> dpmin[1];
	cin >> dpmin[2];
	dpmax[0] = dpmin[0];
	dpmax[1] = dpmin[1];
	dpmax[2] = dpmin[2];
	int idx0;
	int idx1;
	int idx2;
	for (int i = 1; i < N; i++)
	{
		cin >> input[0];
		cin >> input[1];
		cin >> input[2];

		idx0 = max(dpmax[0], dpmax[1]) + input[0];
		idx1 = max({ dpmax[0], dpmax[1], dpmax[2] }) + input[1];
		idx2 = max(dpmax[1], dpmax[2]) + input[2];
		dpmax[0] = idx0;
		dpmax[1] = idx1;
		dpmax[2] = idx2;

		idx0 = min(dpmin[0], dpmin[1]) + input[0];
		idx1 = min({ dpmin[0], dpmin[1], dpmin[2]}) + input[1];
		idx2 = min(dpmin[1], dpmin[2]) + input[2];
		dpmin[0] = idx0;
		dpmin[1] = idx1;
		dpmin[2] = idx2;
	}
	cout << max({ dpmax[0], dpmax[1], dpmax[2] }) <<" " <<  min({dpmin[0], dpmin[1], dpmin[2]});


	return 0;
}