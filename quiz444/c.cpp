#include <iostream>
#include <vector>
#include <map>
#include <queue>



using namespace std;

int a[1010][1010];



int main(){
	
	int n,m;
	cin >> m >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	int k;
	cin >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == k){
				cout << "true";
				return 0;
			}
		}
	}

	cout << "false";



	return 0;
}