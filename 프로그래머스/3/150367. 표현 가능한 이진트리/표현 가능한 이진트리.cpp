#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
// 수를 이진 형태로 만들기
string MakeBinary(ll num)
{
    string binary = "";
    while(num > 0)
    {
        binary.push_back((num % 2) + '0');
        num /= 2;
    }
    // push_back으로 앞 자리부터 채워지므로 뒤집어야 함
    reverse(binary.begin(), binary.end());
    return binary;
}
// 루트가 0 이면 자식들도 0이어야 한다.
// 서브트리도 그래야하고, 만약 루트가 0인데 자식에 1이 있다면
// 해당 수는 이진 트리로 표현할 수 없다.
bool Check(const string& binary, ll left, ll right)
{
    if (left >= right)
    {
        return true;
    }
    ll mid = left / 2 + right / 2;
    
    if(binary[mid] == '0')
    {
        for(int i = left; i <= right; i++)
        {
            if(binary[i] == '1')
            {
                return false;
            }
        }
    }
    return Check(binary, left, mid - 1) && 
        Check(binary, mid + 1, right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(ll num : numbers)
    {
        string binary = MakeBinary(num);
        int targetLength = 1;
        while(targetLength < binary.length())
        {
            // 이진 트리의 개수인 1, 3, 7, ... 의 꼴이 되어야 한다.
            targetLength = targetLength * 2 + 1;
        }
        ll frontZeroLength = targetLength - binary.length();
        // 앞의 더미 채우기
        binary = string(frontZeroLength, '0') + binary;
        answer.push_back(Check(binary, 0, targetLength - 1));
    }
    return answer;
}