#include <bits/stdc++.h>
using namespace std;

map < int, Node* > lst;

void build_siblings(Node* root) {
	if (!root)
		return;
	if (lst.count(root->level))
		root->right_sibling = lst[root->level];	

	lst[root->level] = root;	

	if (root->right)
		build_siblings(root->right);	
	if (root->left)
		build_siblings(root->left);
}
