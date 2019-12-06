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


int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}


int main(){
	
	int n, m;
	cin >> n >> m;

	cout << gcd(n, m);

	return 0;
}


