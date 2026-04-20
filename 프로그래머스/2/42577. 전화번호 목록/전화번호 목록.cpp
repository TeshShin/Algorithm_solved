#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_set<string> Hash;
    for(const string Numbers : phone_book)
        Hash.insert(Numbers);

    for(const string Numbers : phone_book) {
        string PhoneNumber = "";
        for(const char Number : Numbers) {
            PhoneNumber += Number;
            if(Hash.find(PhoneNumber) != Hash.end() && PhoneNumber != Numbers)
                answer = false;
        }
    }

    return answer;
}