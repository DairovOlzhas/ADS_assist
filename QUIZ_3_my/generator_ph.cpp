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
#define _ << " " <<

using namespace std;

int main(){
	
	freopen("test.txt", "w", stdout);
	srand( time( 0 ) ); 

	ull n = rand()%100000+1;
	ull m = rand()%100000+1;
	cout << n _ m << endl;
	
	for(ull i = 0; i < n; i++){
		ull len = rand()%1000+1;
		string ph = "";
		for(int j = 0; j < len; j++){
			ph+=char('0'+rand()%10);
		}
		cout << ph << endl;
	}


	for(ull i = 0; i < m; i++){
		ull len = rand()%1000+1;
		string ph = "";
		for(int j = 0; j < len; j++){
			ph+=char('0'+rand()%10);
		}
		cout << ph << endl;
	}
	system("pause");


	return 0;
}
