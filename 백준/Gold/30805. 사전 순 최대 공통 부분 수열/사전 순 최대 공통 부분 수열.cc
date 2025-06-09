#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, num;
vector<int> A, B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		A.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		B.push_back(num);
	}
	bool flag = true;
	vector<int> ans;
	int max_a, a_idx, max_b, b_idx;
	while (true)
	{
		while (true)
		{
			if (A.size() == 0 || B.size() == 0)
			{
				flag = false;
				break;
			}
			max_a = *max_element(A.begin(), A.end());
			a_idx = max_element(A.begin(), A.end()) - A.begin();
			max_b = *max_element(B.begin(), B.end());
			b_idx = max_element(B.begin(), B.end()) - B.begin();
			if (max_a == max_b) break;
			else if (max_a > max_b) A.erase(A.begin() + a_idx);
			else B.erase(B.begin() + b_idx);
		}
		if (!flag) break;

		// 최댓값을 ans벡터에 push
		ans.push_back(max_a);

		// 최댓값보다 작은 인덱스의 값들을 제거
		int tmp = 0;
		for (int i = a_idx + 1; i < A.size(); i++)
		{
			A[tmp] = A[i];
			tmp++;
		}
		for (int i = 0; i < a_idx + 1; i++)
		{
			A.pop_back();
		}
		tmp = 0;
		for (int i = b_idx + 1; i < B.size(); i++)
		{
			B[tmp] = B[i];
			tmp++;
		}
		for (int i = 0; i < b_idx + 1; i++)
		{
			B.pop_back();
		}
	}
	if (!ans.empty())
	{
		cout << ans.size() << '\n';
		for (int v : ans) cout << v << " ";
	}
	else cout << 0;
	

	return 0;
}