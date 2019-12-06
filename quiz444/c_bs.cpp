#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>


using namespace std;



int main(){
	

	int n,m;
	cin >> n >> m;
	int a[n*m];
	for(int i = 0; i < n*m; i++){
		cin >> a[i];
	}
	int k;
	cin >> k;
	int r = n*m-1,l = 0;
	bool find = false;
	while(r>=l){
		int m = (r+l)/2;

		if(l == r && a[l] == k){
			find = true;
		}
		if(a[m] > k){
			r = m-1;
		}else if(a[m] < k){
			l = m+1;
		}else{
			find = true;
			break;
		}
	}
	if(find)
		cout << "true";
	else
		cout << "false";

	return 0;
}