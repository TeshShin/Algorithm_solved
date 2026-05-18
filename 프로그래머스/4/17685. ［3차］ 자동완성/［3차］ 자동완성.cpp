#include <string>
#include <vector>
#include <array>
#include <memory>

using namespace std;

struct Node
{
    array<unique_ptr<Node>, 26> children;
    int count = 0;
};

void Insert(Node& root, const string& word)
{
    Node* node = &root;
    for(const char c : word)
    {
        int index = c - 'a';
        if(node->children[index] == nullptr)
        {
            node->children[index] = make_unique<Node>();
        }
        node = node->children[index].get();
        node->count++;
    }
}

int GetInputCount(Node& root, const string& word)
{
    Node* node = &root;
    int count = 0;
    for(const char c : word)
    {
        int index = c - 'a';
        node = node->children[index].get();
        count++;
        if(node->count == 1)
        {
            break;
        }
    }
    return count;
}

int solution(vector<string> words) {
    int answer = 0;
    Node trie;
    for(const string& word : words)
    {
        Insert(trie, word);
    }
    for(const string& word : words)
    {
        answer += GetInputCount(trie, word);
    }
    return answer;
}