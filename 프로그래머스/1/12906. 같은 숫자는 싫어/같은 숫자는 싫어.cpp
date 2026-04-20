#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> Stack;
    int Count = 0;
    for(const int Num : arr)
    {
        if(answer.empty()) 
        {
            answer.push_back(Num);
            continue;
        }
        if(Num != answer[Count])
        {
            answer.push_back(Num);
            Count++;
        }

    }
    return answer;
}