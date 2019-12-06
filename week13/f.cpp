#include <bits/stdc++.h>
#include <iostream>
// #include <unordered_map>
#define vi vector <ull>
#define ii pair<ull,ull>
#define vii vector<ii>

#define seti set<ull>
#define mii map<ull,ull>
#define um unordered_map
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100100
#define _ << " " <<

using namespace std;



void solve(){
	
	int n,m;
	cin >> n >> m;
	int mxn = 0, mxm = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		mxn = max(x,mxn);
	}
	
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		mxm = max(x,mxm);
	}

	if(mxn < mxm){
		cout << "MechaGodzilla" << endl;
	}else
		cout << "Godzilla" << endl;

}

int main(){

	int q;
	cin >> q;
	// q = 1;
	for(int i = 0; i < q; i++){
		// cout << "Scenario #" << i+1 << ":" << endl;

		solve();
	}


	return 0;
}
