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

ull mod;

string get_hash(string s){

	ull hash = 0;
	ull p = 11;
	ull pow = 1ll;
	for(int i = 0; i < s.size(); i++){
		hash = (hash + ((s[i]-47)*pow)%mod)%mod;
		pow = (pow*p)%mod;
	}

	return to_string(hash);
}


int main(){
	mod = 1e9+7;
	int n;
	cin >> n;
	map<string,bool> hashs;
	vector<string> s;
	for(int i = 0; i < n; i++){
		string a,b;
		cin >> a >> b;
		s.push_back(a);
		s.push_back(b);
		hashs[a] = true;
		hashs[b] = true;
	}

	vector<pair<string,string> > ans;

	for(int i = 0; i < 2*n; i++){
		string hash = get_hash(s[i]);
		if(hashs[hash]){
			ans.push_back({s[i],hash});
		}
	}




	for(int i = 0; i < n; i++){
		cout << "Hash of string \"" << ans[i].fi << "\" is " << ans[i].se << endl;
	}



	return 0;
}