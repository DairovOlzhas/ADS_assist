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


  


int main(){
	ull MAXN = 50;
	freopen("test.txt", "w", stdout);
	srand( time( 0 ) ); 

	ull n = rand()%MAXN+1;
	// n = 3;
	// n = MAXN;

	int a[n][n];

	for(int i = 0; i < n; i++){
		a[i][i] = 0;
		for(int j = i+1; j < n; j++){
			if(rand()%500||true){
				a[i][j] = rand()%100+1;
				a[j][i] = a[i][j];
			}else{
				a[i][j] = 0;
				a[j][i] = 0;
			}
		}
	}

	// unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// shuffle (s.begin(), s.end(), std::default_random_engine(seed));
	cout << n << endl;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}




	system("pause");


	return 0;
}
