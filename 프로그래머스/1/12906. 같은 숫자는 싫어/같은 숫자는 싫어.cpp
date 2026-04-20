#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (const int num : arr)
    {
        if (answer.empty() || answer.back() != num)
        {
            answer.push_back(num);
        }
    }

    return answer;
}