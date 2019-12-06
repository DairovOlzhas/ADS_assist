#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main(){

	int n;
	cin >> n;
	int mx = 0;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(a[i], mx);
	}

	int cnt = 0, ans = 0;

	for(int i = 0; i < n; i++){
		if(a[i] == mx){
			cnt++;
		}else{
			ans = max(ans, cnt);
			cnt = 0;
		}
	}

	cout << ans;

	return 0;
}