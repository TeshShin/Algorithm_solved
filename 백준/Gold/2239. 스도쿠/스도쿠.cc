#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool Row[9][10];
bool Col[9][10];
bool Box[9][10];
int sudoku[9][9];

// 1. 행에서 가능한 숫자 배열
// 2. 열에서 가능한 숫자 배열
// 3. 사각형에서 가능한 숫자 배열

int GetBoxIndex(int row, int col)
{
	return (row / 3) * 3 + (col / 3);
}


bool Solve()
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (sudoku[r][c] != 0) continue;
			int boxIndex = GetBoxIndex(r, c);
			for (int num = 1; num <= 9; num++)
			{
				if (!Row[r][num] && !Col[c][num] && !Box[boxIndex][num])
				{
					sudoku[r][c] = num;
					Row[r][num] = true;
					Col[c][num] = true;
					Box[boxIndex][num] = true;
					if (Solve())
					{
						return true;
					}
					sudoku[r][c] = 0;
					Row[r][num] = false;
					Col[c][num] = false;
					Box[boxIndex][num] = false;
				}
			}
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int r = 0; r < 9; r++)
	{
		string input;
		cin >> input;
		for (int c = 0; c < 9; c++)
		{
			sudoku[r][c] = input[c] - '0';
			if (sudoku[r][c] != 0)
			{
				Row[r][sudoku[r][c]] = true;
				Col[c][sudoku[r][c]] = true;
				Box[GetBoxIndex(r, c)][sudoku[r][c]] = true;
			}
		}
	}

	if (Solve())
	{
		for (int r = 0; r < 9; r++)
		{
			for (int c = 0; c < 9; c++)
			{
				cout << sudoku[r][c];
			}
			cout << '\n';
		}
	}

	// 출력확인
	/*
	cout << "행" << '\n';
	for (int r = 0; r < 9; r++)
	{
		for (int c = 1; c < 10; c++)
		{
			cout << Row[r][c];
		}
		cout << '\n';
	}
	cout << "열" << '\n';
	for (int r = 0; r < 9; r++)
	{
		for (int c = 1; c < 10; c++)
		{
			cout << Col[r][c];
		}
		cout << '\n';
	}
	cout << "박스" << '\n';
	for (int r = 0; r < 9; r++)
	{
		for (int c = 1; c < 10; c++)
		{
			cout << Box[r][c];
		}
		cout << '\n';
	}
	*/
	return 0;
};