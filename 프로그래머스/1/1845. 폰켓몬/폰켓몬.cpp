#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int,int> pokemons;
    int answer = 0;
    for(const int& num : nums)
    {
        pokemons[num] = 1;
    }
    answer = min(pokemons.size(), (nums.size() / 2));
    return answer;
}