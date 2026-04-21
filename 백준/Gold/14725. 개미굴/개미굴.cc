#include<iostream>
#include<vector>
#include<map>
#include<memory>
#include<algorithm>
using namespace std;


struct Node
{
	map<string, unique_ptr<Node>> Children;
};

void Insert(Node& CurrentNode, const vector<string>& Path, int Depth)
{
    if (Depth == Path.size())
        return;

    const string& Name = Path[Depth];

    if (CurrentNode.Children.find(Name) == CurrentNode.Children.end())
    {
        CurrentNode.Children[Name] = make_unique<Node>();
    }

    Insert(*CurrentNode.Children[Name], Path, Depth + 1);
}

void Print(const Node& CurrentNode, int Depth)
{
    for (const pair<const string, unique_ptr<Node>>& Child : CurrentNode.Children)
    {
        const string& Name = Child.first;
        const unique_ptr<Node>& ChildNode = Child.second;
        for (int i = 0; i < Depth; i++)
        {
            cout << "--";
        }
        cout << Name << '\n';
        
        Print(*ChildNode, Depth + 1);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int N, K;
    unique_ptr<Node> Root = make_unique<Node>();
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        vector<string> Path;
        string Name;
        for (int j = 0; j < K; j++)
        {
            cin >> Name;
            Path.push_back(Name);
        }
        Insert(*Root, Path, 0);
    }
    Print(*Root, 0);
	return 0;
}