#include<iostream>

using namespace std;

int stair, n[302], dp[302];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> stair;
    for (int i = 1; i <= stair; i++)
    {
        cin >> n[i];
        dp[i] = max(dp[i-2] + n[i], dp[i-3] + n[i - 1] + n[i]);
    }
    cout << dp[stair];
    return 0;
}