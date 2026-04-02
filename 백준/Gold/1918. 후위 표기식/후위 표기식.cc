#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string input;
	stack<char> operators;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		char curr = input[i];
		if (curr == '(')
		{
			operators.push(curr);
		}
		else if (curr == ')')
		{
			while (!operators.empty() && operators.top() != '(')
			{
				cout << operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else if (curr == '+' || curr == '-')
		{
			while (!operators.empty() && operators.top() != '(')
			{
				cout << operators.top();
				operators.pop();
			}
			operators.push(curr);
		}
		else if (curr == '*' || curr == '/')
		{
			while (!operators.empty() && operators.top() != '(' && operators.top() != '+' && operators.top() != '-')
			{
				cout << operators.top();
				operators.pop();
			}
			operators.push(curr);
		}
		else
		{
			cout << curr;
		}
	}
	while (!operators.empty())
	{
		cout << operators.top();
		operators.pop();
	}
	return 0;
}