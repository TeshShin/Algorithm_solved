#include<iostream>
using namespace std;

int memo[41];

int fibonacci(int n) {
    if (n == 0) {
        return memo[n] = 0;
    }
    else if (n == 1) {
        return memo[n] = 1;
    }
    else if (memo[n]) {
        return memo[n];
    }
    else {
        return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        if (!N) {
            cout << 1 << " " << 0 << endl;
        }
        else {
            cout << fibonacci(N - 1) << " " << fibonacci(N) << endl;
        }
    }
}