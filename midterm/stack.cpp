#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <utility> 
#include <sstream>   
using namespace std;

using namespace std;

class Node{
	public:
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}

};

class stack{
public:
	Node<T> *top;
	int sz;

	Stack(){
		top = NULL;
		sz = 0;
	}

	void push(int data){
		Node<T> *node = new Node(data);
		node->next = top;
		top = node;
		sz++;
	}

	bool empty(){
		return sz == 0;
	}

	void pop(){
		if(!empty()){
			top = top->next;
		}
	}

	int top(){
		return top->data;
	}

	int size(){
		return sz;
	}
};


int main(){

	int n;
	cin >> n;
	int H[n];
	for(int i = 0; i < n; i++){
		cin >> H[i];
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; i++){
		int l,r;
		stack<int> st;
		cin >> l >> r;
		st.push(H[l]);
		for(int i = l+1; i <= r; i++){
			if(st.top() < H[i])
				st.push(H[i]);
		}
		cout << st.size() << endl;
		while(!st.empty())
			st.pop();
	}
	return 0;
}
