#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> GetPi(const string& s)
{
	int Length = static_cast<int>(s.size());
	vector<int> Pi(Length, 0);
	int j = 0;
	for (int i = 1; i < Length; i++)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = Pi[j - 1];
		}
		if (s[i] == s[j])
		{
			j++;
			Pi[i] = j;
		}
	}
	return Pi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string Input;
	cin >> Input;
	int Length = static_cast<int>(Input.size());
	int Answer = 0;
	for (int i = 0; i < Length; i++)
	{
		string Sub = Input.substr(i);
		vector<int> Pi = GetPi(Sub);
		for (int Value : Pi)
		{
			Answer = max(Value, Answer);
		}
	}
	cout << Answer;
	return 0;
}