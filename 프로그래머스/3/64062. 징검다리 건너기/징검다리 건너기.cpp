#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200'000'001;
    deque<int> dq;
    for(int i = 0; i < stones.size(); i++)
    {
        // 현재 구간 보다 앞에 있는 인덱스 제거
        while(!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        // 현재 넣으려는 돌보다 큐 안의 돌이 작거나 같으면 제거
        while(!dq.empty() && stones[dq.back()] <= stones[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        
        // 첫 구간 시작부터
        if(i >= k - 1)
        {
            int windowMax = stones[dq.front()];
            answer = min(answer, windowMax);
        }
    }
    
    return answer;
}