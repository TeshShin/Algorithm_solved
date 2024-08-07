#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int M, S = 0, x; // S 의 원소 : 1 <= x <= 20이지만 인덱스로는 0<= x <= 19라고 생각하자.
	char input[7];
	cin >> M; // 1 <= M <= 3,000,000
	for (int i = 0; i < M; i++) {
		cin >> input;

		if (input[0] == 'a') {
			if (input[1] == 'd') {
				cin >> x;
				x -= 1;
				S |= (1 << x);
			}
			else {
				S |= (1 << 20) - 1;
			}
		}
		else if (input[0] == 'c') {
			cin >> x;
			x -= 1;
			if (S & (1 << x)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (input[0] == 't') {
			cin >> x;
			x -= 1;
			S ^= (1 << x);
		}
		else if (input[0] == 'e') {
			S = 0;
		}
		else if (input[0] == 'r') {
			cin >> x;
			x -= 1;
			S &= ~(1 << x);
		}
	}


	/*
	for (int i = 19; i >= 0; i--) // 비트 확인
	{
		int temp = (S >> i) & 1;
		cout << temp;
	}
	*/
	return 0;
}
