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

vector<int> solve(string s){
	vector<int> p(s.size());
	p[0] = 0;
	for(int i = 1; i < s.size(); i++){
		int j = p[i-1];
		while(j > 0 && s[i] != s[j]){
			j = p[j-1];
		}
		if(s[i] == s[j]) j++;
		p[i] = j;
	}

	return p;

}


int main(){
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	string s;
	cin >> s;

	vector<int> ans = solve(s);

	for(int i = 0 ; i < ans.size(); i++){
		cout << ans[i] << " ";
	}

	return 0;
}


