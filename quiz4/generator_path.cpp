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


  
string generateString(ull len){
	string res = "";
	for(ull i = 0; i < len; i++){
		res += (rand()%2)?'R':'L';
	}
	return res;
}

int main(){
	ull MAXN = 100000;
	freopen("test.txt", "w", stdout);
	srand( time( 0 ) ); 

	ull m = rand()%MAXN+1;
	ull n = rand()%MAXN+1;
	// n = 3;
	vector<int> s;

	for(int i = 1; i <= n; i++){
		s.pb(i);
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle (s.begin(), s.end(), std::default_random_engine(seed));
	cout << n _ m << endl;

	for(int i = 0; i < n; i++){
		cout << s[i] << " ";
	}

	cout << endl;

	for(int i = 0; i < m; i++){
		cout << generateString(rand()%10+2) << endl;
	}




	system("pause");


	return 0;
}
