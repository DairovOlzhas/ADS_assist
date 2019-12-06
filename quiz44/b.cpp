#include <bits/stdc++.h>
#include <iostream>


using namespace std;

class Node{
	public:
	int data;
	Node *left, *right;

	Node(int data){
		this->data = data;
		left = right = NULL;
	}

};


Node* insert(Node *node, int key){
	if(node == NULL) return new Node(key);

	if(node->data < key)
		node->right = insert(node->right, key);
	else
		node->left = insert(node->left, key);

	return node;

}

bool findpath(Node* root, string s){
	Node *cur = root;
	if(cur == NULL) return false;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'R'){
			cur = cur->right;
		}else{
			cur = cur->left;
		}
		if(cur == NULL) return false;
	}
	return true;
}


int main(){
	
	
	int n,m;
	cin >> n >> m;
	Node *root = NULL;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		root = insert(root, x);
	}

	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		if(findpath(root,s)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}

	return 0;
}


