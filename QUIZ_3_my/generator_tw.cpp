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
ull plen;
string p;
string toUpper(string s){
    string res = "";
    res += char('A'+(s[0]-'a')) + s.substr(1);
    return res;
}
  
string generateString(ull len, bool t){
	string res = "";
	for(ull i = 0; i < len; i++){
		res += char('a'+rand()%26);
	}
	// if(t){
	// 	ull pref = rand()%(min(200,int(plen)))+1;
	// 	res = p.substr(max(0,int(p.size()-pref))) + res;
	// }
	return res;
}

int main(){
	
	freopen("test.txt", "w", stdout);
	srand( time( 0 ) ); 

	plen = rand()%400+1;
	p = toUpper(generateString(plen, 0));
	cout << p << endl;
	ull n = rand()%10+1;
	cout << n << endl;
	
	for(ull i = 0; i < n; i++){
		ull len = rand()%400+1;

		string t = toUpper(generateString(len, 1));
		cout << t << endl;
	}


	system("pause");


	return 0;
}
