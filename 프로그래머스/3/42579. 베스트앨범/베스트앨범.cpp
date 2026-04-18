#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

using P = pair<int,int>;
bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}
bool Pcmp(const P& a, const P& b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<P>> lists;
    unordered_map<string, int> totalplays;
    for(int i = 0; i < genres.size(); i++)
    {
        lists[genres[i]].push_back({plays[i], i});
        totalplays[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> totalsort(totalplays.begin(), totalplays.end());
    
    sort(totalsort.begin(), totalsort.end(), cmp);
    
    for(auto& list : lists)
    {
        vector<P>& playAndIndex = list.second;
        sort(playAndIndex.begin(), playAndIndex.end(), Pcmp);
    }
    for(auto iter = totalsort.begin(); iter != totalsort.end(); iter++)
    {
        vector<P>& playAndIndex = lists[iter->first];
        int listSize = playAndIndex.size();
        for(int j = 0; j < 2 && j < listSize; j++)
        {
            answer.push_back(playAndIndex[j].second);
        }
    }
    
    
    return answer;
}