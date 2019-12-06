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

vector<int> g[100100];
bool used[100100];
int cnt;
void dfs(int v){
	used[v] = true;
	cnt++;
	for(int i = 0; i < g[v].size(); i++){
		int to = g[v][i];
		if(!used[to]){
			dfs(to);
		}
	}
}

void bfs(int v){

	queue<int> q;

	q.push(v);
	used[v] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			if(!used[to]){
				used[to] = true;
				q.push(to);-
			}

		}
	}



}


int main(){
	
	int n, v;
	cnt = 0;
	cin >> n >> v;
	// 0 1 1
	// 1 0 0
	// 1 0 0

	for(int i = 0; i < 100100; i++){
		used[i] = false;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			if(x == 1){
				g[i+1].push_back(j+1);
			}
		}
	}

	dfs(v);
	cout << cnt;
	return 0;
}


