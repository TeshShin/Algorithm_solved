#include <iostream>
using namespace std;

long long k, x, T;

long long fibo[50'000'001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fibo[0] = 1;
	fibo[1] = 1;
	for (long long i = 2; i <= 50'000'000; i++)
	{
		fibo[i] = (fibo[i - 1] + fibo[i - 2]);
	}
	cin >> T;
	while (T--)
	{
		cin >> k >> x;
		bool bCan = false;
		if (k == 1)
		{
			for (long long i = 1; ; i++)
			{
				if (fibo[i] >= x)
				{
					if (fibo[i] == x)
					{
						bCan = true;
					}
					break;
				}
			}
		}
		else if (k == 2)
		{
			for (long long i = 1; ; i++)
			{
				for (long long j = 1; ; j++)
				{
					if ((fibo[i] + fibo[j]) >= x)
					{
						if ((fibo[i] + fibo[j]) == x)
						{
							bCan = true;
						}
						break;
					}
				}
				if (bCan) break;
				else if (fibo[i] >= x) break;
			}
		}
		else if (k == 3)
		{
			for (long long i = 1; ; i++)
			{
				for (long long j = 1; ; j++)
				{
					for (long long k = 1; ; k++)
					{
						if ((fibo[i] + fibo[j] + fibo[k]) >= x)
						{
							if ((fibo[i] + fibo[j] + fibo[k]) == x)
							{
								bCan = true;
							}
							break;
						}
					}
					if (bCan) break;
					else if (fibo[i] + fibo[j] >= x) break;
				}
				if (bCan) break;
				else if (fibo[i] >= x) break;
			}
		}
		if (bCan)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}

	return 0;
}