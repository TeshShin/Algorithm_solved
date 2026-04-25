#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool Compare(const vector<int>& a, const vector<int>& b)
{
    if(a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] > b[0];
}


int solution(vector<vector<int>> scores) {
    int Atti = scores[0][0], Eval = scores[0][1];
    int Sum = Atti + Eval;
    sort(scores.begin(), scores.end(), Compare);
    int MaxEval = 0;
    int Aboves = 1;
    for(int i = 0; i < scores.size(); i++)
    {
        int CurrAtti = scores[i][0];
        int CurrEval = scores[i][1];
        int CurrSum = CurrAtti + CurrEval;
        if(CurrEval >= MaxEval)
        {
            MaxEval = CurrEval;
            if(CurrSum > Sum)
            {
                Aboves++;
            }
        }
        else
        {
            if(CurrAtti == Atti && CurrEval == Eval)
            {
                return -1;
            }
        }
    }
    
    return Aboves;
}