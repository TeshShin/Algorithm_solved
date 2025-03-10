#include<iostream>
using namespace std;	

int N;
char tree[26][2];
void preorder(char node) {
	if (node == '.') return;
	cout << node;
	preorder(tree[node - 'A'][0]);
	preorder(tree[node - 'A'][1]);
}
void inorder(char node) {
	if (node == '.') return;
	inorder(tree[node - 'A'][0]);
	cout << node;
	inorder(tree[node - 'A'][1]);
}
void postorder(char node) {
	if (node == '.') return;
	postorder(tree[node - 'A'][0]);
	postorder(tree[node - 'A'][1]);
	cout << node;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		tree[root - 'A'][0] = left;
		tree[root - 'A'][1] = right;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');

	return 0;
}