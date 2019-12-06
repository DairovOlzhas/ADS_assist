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

int main(){
	
	freopen("test.txt", "w", stdout);
	srand( time( 0 ) ); 

	ull n = rand()%100+1;
	cout << n << endl;
	for(ull i = 0; i < n; i++){
		cout << rand()%1000+1 << " ";
	}
	cout << endl;

	ull q = rand()%100;
	cout << q << endl;
	for(int i = 0; i < q; i++){
		ull l = rand()%n;
		ull r = l + rand()%(n-l);
		cout << l << " " << r << endl;
	}

	// cout << 10000 << endl;
	// for(int i = 0; i < 10000; i++){
		// cout << 1000000000 << " ";
	// }
	system("pause");


	return 0;
}
