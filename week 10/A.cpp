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

vector<int> solve(string s, string t){
	vector<int> res;
	string a = t+" "+s;
	vector<int> p(a.size());
	p[0] = 0;
	for(int i = 1; i < a.size(); i++){
		int j = p[i-1];
		while(j > 0 && a[i] != a[j]){
			j = p[j-1];
		}
		if(a[i] == a[j]) j++;
		p[i] = j;
	}

	for(int i = t.size(); i < a.size(); i++){
		if(p[i] >= t.size()){
			res.push_back(i-2*t.size());
		}
	}
	return p;

}


int main(){
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	string s,t;
	cin >> s >> t;

	vector<int> ans = solve(s,t);

	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";		
	}
	return 0;
}


