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

int binary_search(int arr[], int l, int r, int x){

	while(l <= r){
		int mid = l + (r-l)/2;

		if(arr[mid] == x) return mid;

		if(x > a[mid]){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}

	return -1;	

}


int main(){
	


	return 0;
}


