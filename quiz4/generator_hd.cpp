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
#define _ << " " <<

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
  
string generateString(ull len){
	string res = "";
	for(ull i = 0; i < len; i++){
		res += char('0'+rand()%10);
	}
	return res;
}

int main(){
	ull MAXN = 1000;
	freopen("test.txt", "w", stdout);
	srand( time( 0 ) ); 
	mod = 1e9+7;
	ull n = rand()%MAXN+1;
	// n = 3;
	vector<string> s;

	for(int i = 0; i < n; i++){
		string p = generateString(rand()%100+1);
		string hash = get_hash(p);
		s.push_back(p);
		s.push_back(hash);
	}


	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle (s.begin(), s.end(), std::default_random_engine(seed));
	cout << n << endl;
	for (string& x: s) cout << x << endl;


	system("pause");


	return 0;
}
