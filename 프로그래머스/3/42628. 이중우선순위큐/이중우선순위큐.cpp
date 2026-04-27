#include <string>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> MaxPQ;
    priority_queue<int, vector<int>, greater<int>> MinPQ;
    unordered_map<int,int> NumLife;
    int QueueSize = 0;
    
    for(auto& oper : operations)
    {
        char op = oper[0];
        int num = stoi(oper.substr(2));
        switch(op)
        {
            case 'I':
                MaxPQ.push(num);
                MinPQ.push(num);
                NumLife[num]++;
                QueueSize++;
                break;
            case 'D':
                if(QueueSize > 0)
                {
                    if(num > 0)
                    {
                        while(!MaxPQ.empty() && NumLife[MaxPQ.top()] == 0)
                        {
                            MaxPQ.pop();
                        }
                        NumLife[MaxPQ.top()]--;
                        MaxPQ.pop();
                        
                    }
                    else
                    {
                         while(!MinPQ.empty() && NumLife[MinPQ.top()] == 0)
                        {
                            MinPQ.pop();
                        }
                        NumLife[MinPQ.top()]--;
                        MinPQ.pop();
                    }
                    QueueSize--;
                }
                break;
        }
        if(QueueSize == 0)
        {
            MaxPQ = priority_queue<int>();
            MinPQ = priority_queue<int, vector<int>, greater<int>>();
        }
    }
    if(QueueSize == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        while(!MaxPQ.empty() && NumLife[MaxPQ.top()] == 0)
        {
            MaxPQ.pop();
        }
        while(!MinPQ.empty() && NumLife[MinPQ.top()] == 0)
        {
            MinPQ.pop();
        }
        answer.push_back(MaxPQ.top());
        answer.push_back(MinPQ.top());
    }
    
    return answer;
}