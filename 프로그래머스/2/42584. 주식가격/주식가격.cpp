#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int savepoint = 0;
    for (int i = 0; i < prices.size(); i++) {
        int time = 0;
        if (i == prices.size() - 1) { // 제일 마지막 원소는 시간이 없음
            answer.push_back(0);
            break;
        }
        for (int j = i + 1; j < prices.size(); j++) {
            time++;
            if (prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(time); 
    }


    return answer;
}