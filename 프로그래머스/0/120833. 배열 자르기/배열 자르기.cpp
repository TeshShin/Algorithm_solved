#include <vector>
using namespace std;

vector<int> solution(vector<int> numbers, int x, int y)
{
    vector<int> answer;
    int n = numbers.size();

    for (int i = x; i <= y; i++)
    {
        answer.push_back(numbers[i]);
    }

    return answer;
}