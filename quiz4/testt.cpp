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

string hash_to_string(ull hash){
	string s;
	ull p = 11;

	while(hash >= 11){
		s+= char((hash%11)+47);
		hash/=11;
	}
	s+=char((hash%11)+47);

	return s;

}

int main(){
	mod = 1e9+7;

	// ull s;
	string s;

	cin >> s;

	// cout << hash_to_string(s);	
	cout << get_hash(s);
	return 0;
}