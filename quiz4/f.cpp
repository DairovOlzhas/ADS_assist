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

int cnt;

int p[100100];
int sz[100100];
void make_set(int v){
	p[v] = v;
}

int find_parent(int v){
	if(p[v] == v) return v;
	return p[v] = find_parent(p[v]);
}

void union_set(int a, int b){	
	a = find_parent(a);
	b = find_parent(b);

	if(a != b){
		p[a] = b;
		if(sz[a] > sz[b])
			swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
		cnt--;
	}	
}


int main(){
	int n,m,k;
	cin >> n >> m >> k;
	cnt = n;
	for(int i = 0; i < 100100; i++){
		make_set(i);
	}

	for(int i = 0; i < m; i++){
		int x,y;
		cin >> x >> y;
		union_set(x, y);
	}

	if(cnt > k){
		cout << "NO";
	}else
		cout << "YES";

	return 0;
}