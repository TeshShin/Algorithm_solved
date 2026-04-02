#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const long long mod = 1'000'000'007;
struct FMatrix2
{
	long long M[2][2];

	static FMatrix2 Identity()
	{
		FMatrix2 result;
		result.M[0][0] = 1;
		result.M[0][1] = 0;
		result.M[1][0] = 0;
		result.M[1][1] = 1;
		return result;
	}
};

FMatrix2 Multiply(const FMatrix2& left, const FMatrix2& right)
{
	FMatrix2 result;
	result.M[0][0] = (left.M[0][0] * right.M[0][0] % mod + left.M[0][1] * right.M[1][0] % mod) % mod;
	result.M[0][1] = (left.M[0][0] * right.M[0][1] % mod + left.M[0][1] * right.M[1][1] % mod) % mod;
	result.M[1][0] = (left.M[1][0] * right.M[0][0] % mod + left.M[1][1] * right.M[1][0] % mod) % mod;
	result.M[1][1] = (left.M[1][0] * right.M[0][1] % mod + left.M[1][1] * right.M[1][1] % mod) % mod;
	return result;
}
FMatrix2 Power(const FMatrix2& mat, long long power)
{
	FMatrix2 result;
	if (power == 0)
	{
		return FMatrix2::Identity();
	}
	if (power == 1)
	{
		return mat;
	}
	FMatrix2 half = Power(mat, power / 2);
	result = Multiply(half, half);

	if ((power % 2) == 1)
		result = Multiply(result, mat);
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n;
	cin >> n;
	FMatrix2 mat;
	mat.M[0][0] = 1;
	mat.M[0][1] = 1;
	mat.M[1][0] = 1;
	mat.M[1][1] = 0;
	mat = Power(mat, n);
	cout << mat.M[0][1];
	return 0;
}