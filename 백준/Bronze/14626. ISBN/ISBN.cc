#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int solve(vector<int> save, int addr)
{
	int answer = 0;
	if (addr == 12)
	{
		for (int i = 0; i < 12; i++)
		{
			if (i % 2 == 1)	answer += save[i] * 3;
			else answer += save[i];
		}
		return (10 - (answer % 10)) % 10;
	}
	else
	{
		for (int i = 0; i < 12; i++)
		{
			if (addr == i) continue;
			if (i % 2 == 1)	answer += save[i] * 3;
			else answer += save[i];
		}
		return (10 - ((save[12] + answer) % 10)) % 10;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char input;
	vector<int> save;
	int addr = -1;
	for(int i = 0; i < 13; i++)
	{
		cin >> input;
		if (input == '*')
		{
			save.push_back(-1);
			addr = i;
			continue;
		}
		save.push_back(input - '0');
	}
	if ((addr % 2) == 1)
	{
		int answer = solve(save, addr);
		switch (answer)
		{
		case 1:
			cout << 7;
			break;
		case 2:
			cout << 4;
			break;
		case 3:
			cout << 1;
			break;
		case 4:
			cout << 8;
			break;
		case 6:
			cout << 2;
			break;
		case 7:
			cout << 9;
			break;
		case 8:
			cout << 6;
			break;
		case 9:
			cout << 3;
			break;
		default:
			cout << answer;
			break;
		}
	}
	else
	{
		cout << solve(save, addr);
	}


	return 0;
}