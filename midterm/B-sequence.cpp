#include <iostream>
#include <vector>
using namespace std;


class Node{
public:
	int cnt;
	int data;
	Node *left;
	Node *right;

	Node(int data){
		cnt = 1;
		this->data = data;
		left = NULL; 
		right = NULL;
	}
};
vector<int> ans;
class BST{
public:
	Node* root;
	int mx, sz;

	BST(){
		root = NULL;
		mx = 0;
		sz = 0;
	}

	Node* add(Node* root, int val){
		if(root == NULL){
			sz++;
			mx = max(mx,val);
			return new Node(val);
		}else if(root->data > val){
			root->left =  add(root->left, val);
		}else if(root->data < val){
			root->right = add(root->right, val);
		}else{
			if(val != mx && root->cnt < 2){
				root->cnt++;
				sz++;
			}
		}
		return root;
	}



	void print(Node* root){
		if(root == NULL) return;
		print(root->left);
		cout << root->data << " ";
		if(root->cnt == 2)
			ans.push_back(root->data);
		print(root->right);
	}
};





int main(){
ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
		
	BST *bst = new BST();
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		bst->root = bst->add(bst->root, x);
	}
	int q;
	cin >> q;
	vector<int> anss;
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		bst->root = bst->add(bst->root, x);
		anss.push_back(bst->sz);
	}
	for(int i = 0; i < q; i++){
		cout << anss[i] << endl;
	}
	bst->print(bst->root);
	for(int i = ans.size()-1; i >= 0; i--){
		cout << ans[i] << " ";
	}

	


	return 0;
}
