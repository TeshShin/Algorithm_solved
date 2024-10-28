#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> pokemon;
    vector<string> pokemonName;
    int n, m;
    string input; //포켓몬 이름과 번호가 섞여있으므로 string
    cin >> n >> m;
    vector<string> result;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        pokemonName.push_back(input); // 도감번호 주어질때 포켓몬 이름 찾기
        pokemon.insert(make_pair(input, i)); // 포켓몬 이름이 주어질때 도감번호 빠르게 찾기
    }
    for (int i = 0; i < m; i++) {
        cin >> input;
        if (isdigit(input[0])) { // input 이 숫자면?
            result.push_back(pokemonName[stoi(input) - 1]); // input이 숫자면 1부터이고 배열은 0부터 이므로
        }
        else // 도감 이름
        {
            result.push_back(to_string(pokemon[input])); // result는 string이므로
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n'; // 출력
    }
    return 0;
}