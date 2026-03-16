#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

stack<pair<int,int>> top;
int N;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		while (!top.empty())
		{
			if (input > top.top().first)
			{
				top.pop();
			}
			else
			{
				cout << top.top().second << ' ';
				top.push(make_pair(input, i));
				break;
			}
		}
		if (top.empty())
		{
			top.push(make_pair(input, i));
			cout << 0 << ' ';
		}
	}

	

	return 0;
}