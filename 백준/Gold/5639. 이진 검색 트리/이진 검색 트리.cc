#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v;
void postorder(int s, int e)
{
	if (s >= e) return;
	int idx = s + 1;
	while (idx < e)
	{
		if (v[s] < v[idx]) break;
		idx++;
	}
	// 루트보다 작은 값과 큰 값으로 나눔
	// 좌측부터 호출이므로 좌측 값이 먼저 나옴
	postorder(s + 1, idx);
	postorder(idx, e);
	cout << v[s] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 입력의 끝은 컨트롤+z 아니면 !0 하면댐
	while (cin >> n)
	{
		v.push_back(n);
	}

	postorder(0, v.size());

	return 0;
}