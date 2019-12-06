#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;


class Node{
public:
	ull data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		left = NULL; 
		right = NULL;
	}
};

bool added;

	Node* add(Node* root, ull val){
		if(root == NULL){
			added = true;
			return new Node(val);
		}else if(root->data > val){
			root->left =  add(root->left, val);
		}else if(root->data < val){
			root->right = add(root->right, val);
		}
		return root;
	}

	

	void print(Node *root){
		if(root == NULL)return;
		print(root->left);
		cout << root->data << "->";
		print(root->right);
	}





int main(){
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	cout.tie(NULL);
	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;
		Node *root = NULL;
		for(int i = 0; i < n; i++){
			ull x;
			cin >> x;
			root = add(root, x);
		}

		// tree->print(tree->root);
		// cout << endl;
		for(int i = 0; i < m; i++){
			ull x;
			cin >> x;
			added = false;
			root = add(root, x);
			if(!added){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}


	return 0;
}
