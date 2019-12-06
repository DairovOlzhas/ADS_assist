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

template<typename T>
class Node{
public:
	T data;
	Node<T> *next;

	Node(T data){
		this->data = data;
		next = NULL;
	}
};

template<typename T>
class Queue{
public:
	Node<T> *head, *tail;
	int sz;

	Queue(){
		tail = head = NULL;
		sz = 0;
	}

	void push(T data){
		Node<T> *node = new Node(data);
		if(this->head == NULL){
			head = tail = node;
		}else{
			tail->next = node;
			tail = node;
		}
		sz++;
	}

	T front(){
		return head->data;
	}

	bool empty(){
		return sz == 0;
	}

	void pop(){
		if(!empty()){
			head = head->next;
			sz--;
		}
	}
};

int main(){
	
	


	return 0;
}
