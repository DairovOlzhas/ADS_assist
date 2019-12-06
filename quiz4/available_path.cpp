#include <bits/stdc++.h>
#include <iostream>
// #define vi vector <int>
#define seti set<int>
#define mii map<int,int>
#define ull long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100100

using namespace std;

class Node{
public:
	Node *right, *left;
	int val;

	Node(int val){
		this->val = val;
		left = right = NULL;
	}
};


Node* insert(Node* root, int val){
	if(root == NULL){
		root = new Node(val);
	}else if(root->val < val){
		root->right = insert(root->right, val);
	}else{
		root->left = insert(root->left, val);
	}
	return root;
}

bool find(Node *cur, string path){
	if(cur == NULL) return false;
	for(int i = 0; i < path.size(); i++){
		if(path[i] == 'R'){
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
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		root = insert(root, x);
	}

	for(int i =0; i < m; i++){
		string path;
		cin >> path;
		if(find(root, path)){
			cout << "YES" << endl;
 		}else{
 			cout << "NO" << endl;
 		}
	}



	return 0;
}