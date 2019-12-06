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

ull a[500500];
ull n,q;

ull binsearch(ull val){

	ull l = 0,r = n-1;

	while(l<=r){
		if(l==r)
			return l;
		ull m = (l+r)/2;
		if(val > a[m]){
			l = m+1;
		}else if(val < a[m]){
			r = m;
		}else{
			return m;
		}
	}


}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i = 1; i < n; i++){
		a[i] += a[i-1];
	}

	for(int i = 0; i < q; i++){
		ull x;
		cin >> x;
		cout << binsearch(x)+1 << endl;
	}

	return 0;
}
