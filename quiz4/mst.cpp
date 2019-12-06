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

int p[1010];

void make_set(int v){
	p[v] = v;
}

int find_parent(int v){
	if(p[v] == v) return v;
	return p[v] = find_parent(p[v]);
}

bool union_set(int a, int b){	
	a = find_parent(a);
	b = find_parent(b);

	if(a != b){
		p[a] = b;
		return true;
	}	

	return false;
}


int main(){
	
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++){
		make_set(i);
	}
	// cout << "asdf";
	vector<pair<int, pair<int,int> > > v;
	for(int i= 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(j > i){
				if(a[i][j] == 0){
					union_set(i,j);
				}else{
					v.push_back({a[i][j],{i,j}});				
				}
			}
		}
	}

	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i < v.size(); i++){
		int c = v[i].fi, a = v[i].se.se, b = v[i].se.fi;
		if(union_set(a,b)) ans+=c;
	}

	cout << ans;

	return 0;
}