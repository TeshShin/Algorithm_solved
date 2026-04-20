#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int CompleteProgress = 0;
    int DelayDays = 0;
    while(CompleteProgress < progresses.size())
    {
        bool CanPublish = false;
        int Publishes = 0;
        while(CompleteProgress < progresses.size() && progresses[CompleteProgress] + DelayDays * speeds[CompleteProgress] >= 100)
        {
 
            CanPublish = true;
            Publishes++;
            CompleteProgress++;
        }
        if(CanPublish)
        {
            answer.push_back(Publishes);
        }
        DelayDays++;
    }
    return answer;
}