#include <bits/stdc++.h>
#include <iostream>
#define vi vector <ull>
#define seti set<ull>
#define mii map<ull,ull>
#define ull long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100100

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);

	string n;
	int T;
	getline(cin,n);
	stringstream tt;
	tt << n;
	tt >> T;
	vector<string> ans[T];
	for(int t = 0; t < T; t++){
		string s;
		getline(cin,s);
		stringstream ss;
		ss << s;
		vector<pair<int,int> > v;
		vector<string> words;
		int i = 0;
		while(ss >> s){
			words.push_back(s);
			v.push_back(make_pair(s.size(), i++));
		}

		sort(v.begin(), v.end());
		for(i = 0; i < v.size(); i++ ){
			ans[t].push_back(words[v[i].se]);
		}
	}

	for(int i = 0; i < T; i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
