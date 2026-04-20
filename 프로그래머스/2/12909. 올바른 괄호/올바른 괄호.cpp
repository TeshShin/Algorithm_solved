#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> Left;
    for(const char Char : s)
    {
        if(Char == '(')
        {
            Left.push('(');
        }
        else if (Char == ')')
        {
            if (Left.empty())
                return false;
            else
                Left.pop();
        }
    }
    if(Left.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}