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
	Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}

};

class Stack{
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
	
	


	return 0;
}


