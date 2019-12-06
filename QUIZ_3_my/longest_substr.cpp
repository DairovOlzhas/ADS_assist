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
#define mod 1000000007

using namespace std;

vector<ull> pow_p;

	vector<ull> hash_t, hash_s;

void calcPpow(){
	ull p = 29;
	pow_p.push_back(1);
	for(ull i = 1; i < 10100; i++){
		pow_p[i] = (pow_p[i-1]*p)%mod;
	}
}

void calcHash(vector<ull> &hash, string t){
	hash.push_back(0);

	for(ull i = 1; i <= t.size(); i++){
		hash[i] = (hash[i-1] + ((t[i]-'a'+1)*pow_p[i-1])%mod)%mod;
	}
}

ull get_hash(vector<ull> &hash, int l, int r){
	return ((hash[r] - hash[l-1] + mod)%mod)/pow_p[l-1];
}

int main(){
	
	string s,t;
	cin >> s >> t;
	cout << " asdf";
	calcPpow();

	calcHash(hash_s, s);
	calcHash(hash_t, t);

	
	ull mx = 0;
	vector<string> ans;
	map<ull,bool> s_subtrs;

	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= s.size()-i+1; j++){
			s_subtrs[get_hash(hash_s, j, j+i-1)] = true; 
		}
	}


	for(int i = 1; i <= t.size(); i++){
		for(int j = 1; j <= t.size()-i+1; j++){
			if(s_subtrs[get_hash(hash_t, j, j+i-1)]){
				if(mx != i) ans.clear();
				mx = i;
				ans.push_back(t.substr(j-1,i));
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}


	return 0;
}