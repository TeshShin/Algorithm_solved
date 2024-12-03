#include <iostream>
using namespace std;
int main()
{
    int N, temp, res = 0;
    cin >> N;
    res += (N - 1) * 8;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        res += temp;
    }
    cout << res / 24 << " " << res % 24;
    return 0;
}