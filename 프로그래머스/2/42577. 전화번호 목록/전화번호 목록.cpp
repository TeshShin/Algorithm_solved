#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_set<string> hash;
    for(int i = 0; i < phone_book.size(); i++)
        hash.insert(phone_book[i]);

    for(int i = 0; i < phone_book.size(); i++) {
        string phone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++) {
            phone_number += phone_book[i][j];
            if(hash.find(phone_number) != hash.end() && phone_number != phone_book[i])
                answer = false;
        }
    }

    return answer;
}