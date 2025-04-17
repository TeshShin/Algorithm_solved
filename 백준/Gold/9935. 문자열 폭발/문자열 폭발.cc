#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> ans;
string input;
string bomb;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> input;
	cin >> bomb;
	for (int i = input.length() - 1; i >= 0; i--)
	{
		ans.push(input[i]);
		if (input[i] == bomb[0] && ans.size() >= bomb.length())
		{
			string temp;
			for (int j = 0; j < bomb.length(); j++)
			{
				temp.push_back(ans.top());
				ans.pop();
			}
			if (temp != bomb)
			{
				for (int j = temp.length() - 1; j >= 0 ; j--)
				{
					ans.push(temp[j]);
				}
			}
		}

		
	}
	if (ans.empty()) cout << "FRULA";
	else
	{
		while (!ans.empty())
		{
			cout << ans.top();
			ans.pop();
		}
	}
	return 0;
}