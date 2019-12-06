#include <bits/stdc++.h>
#include <iostream>
// #define vi vector <int>
#define seti set<int>
#define mii map<int,int>
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100100

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


class BST{
public:
	Node *root;

	BST(){
		root = NULL;
	}

	Node* insert(Node *node, int key){
		if(node == NULL) return new Node(key);

		if(node->data < key)
			node->right = insert(node->right, key);
		else if(node->data > key)
			node->left = insert(node->left, key);

		return node;

	}

	Node* search(Node *root, int key){
		if(root == NULL || root->data == key) return root;

		if(root->data > key)
			return search(root->left, key);
		return search(root->right, key);
	}
};


int main(){
	
	


	return 0;
}


