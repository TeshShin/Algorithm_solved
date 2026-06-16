#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    constexpr long long Mod = 1'000'000'007;

    vector<long long> Dp(n + 1, 0);

    Dp[0] = 1;

    if (n >= 1)
    {
        Dp[1] = 1;
    }

    if (n >= 2)
    {
        Dp[2] = 3;
    }

    if (n >= 3)
    {
        Dp[3] = 10;
    }

    for (int i = 4; i <= n; ++i)
    {
        Dp[i] = Dp[i - 1];
        Dp[i] = (Dp[i] + Dp[i - 2] * 2) % Mod;
        Dp[i] = (Dp[i] + Dp[i - 3] * 6) % Mod;
        Dp[i] = (Dp[i] + Dp[i - 4]) % Mod;

        if (i >= 6)
        {
            Dp[i] = (Dp[i] - Dp[i - 6] + Mod) % Mod;
        }
    }

    return static_cast<int>(Dp[n]);
}