#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

using P = pair<int,int>;
bool CompareGenreTotalPlays(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}
bool CompareMusic(const P& a, const P& b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<P>> genreMusics;
    unordered_map<string, int> genreTotalPlays;
    for(int i = 0; i < genres.size(); i++)
    {
        genreMusics[genres[i]].push_back({plays[i], i});
        genreTotalPlays[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> sortedGenres(genreTotalPlays.begin(), genreTotalPlays.end());
    
    sort(sortedGenres.begin(), sortedGenres.end(), CompareGenreTotalPlays);
    
    for(auto& genre : genreMusics)
    {
        vector<P>& musics = genre.second;
        sort(musics.begin(), musics.end(), CompareMusic);
    }
    for(const auto& genre : sortedGenres)
    {
        vector<P>& musics = genreMusics[genre.first];
        int musicCount = musics.size();
        
        for(int j = 0; j < 2 && j < musicCount; j++)
        {
            answer.push_back(musics[j].second);
        }
    }
    
    
    return answer;
}