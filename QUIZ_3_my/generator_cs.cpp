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
  
string generateString(ull len){
	string res = "";
	for(ull i = 0; i < len; i++){
		res += (rand()%2)?char('a'+rand()%26):char('A'+rand()%26);
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

	ull n = rand()%10000+1;
	n = 10000;
	string p = generateString(n);
	if(rand() % 5 == 0){
		cout << generateString(n) << endl;
	}else{
		ull c = rand()%n;
		cout << p.substr(c) + p.substr(0,c) << endl;
	}
	cout << p;


	system("pause");


	return 0;
}
