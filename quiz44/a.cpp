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

int solve(string per, string s){
	string a = per+" "+s;
	vector<int> pre(a.size());
	pre[0] = 0;
	for(int i = 1; i < a.size(); i++){
		int j = pre[i-1];
		while(j>0 && a[j] != a[i]){
			j = pre[j-1];
		}
		if(a[j] == a[i])j++;
		pre[i] = j;
	}
	// cout << a << endl;
	// for(int i = 0; i < a.size(); i++)
	// 	cout << pre[i];
	// cout << endl;
	int res = 0;
	for(int i = 0; i < a.size(); i++){
		if(pre[i] == per.size())
			res++;
	}
	return res;
}


int main(){
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);/

	string s;
	cin >> s;
	int k;
	cin >> k;

	string t;
	cin >> t;

	if(solve(s,t) >= k){
		cout << "YES";
	}else{
		cout << "NO";
	}

	return 0;
}


