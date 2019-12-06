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

bool solve(string per, string s){
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

	for(int i = 2*per.size(); i < a.size(); i+=per.size()){
		if(pre[i] != per.size())
			return false;
	}
	return true;
}


int main(){
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);/

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		bool ans = false;
		for(int i = 1; i <= n/2; i++){
			if(n%i==0 && solve(s.substr(0,i), s)){
				cout << i << endl;
				ans = true;
				break;
			}
		}
		if(!ans){
			cout << n << endl;
		}
		if(t!=0)
		cout << endl;



	}

	return 0;
}


