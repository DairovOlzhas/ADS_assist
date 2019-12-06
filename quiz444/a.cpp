#include <iostream>
#include <vector>
#include <map>
#include <queue>



using namespace std;

int a[1010][1010];



int main(){
	
	int n,m;
	cin >> n >> m;	
	
	queue<pair<pair<int,int>, int> >q;
	
	bool used[n][m];


	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			used[i][j] = 0;
		}
	}

	for(int i = 0; i  < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 2){
				used[i][j] = true;
				q.push(make_pair(make_pair(i,j), 0));
			}
		}
	}

	pair<int,int> dir[4];
	dir[0] = make_pair(0,1);
	dir[1] = make_pair(0,-1);
	dir[2] = make_pair(1,0);
	dir[3] = make_pair(-1,0);

	
	int ans = 0;
	while(!q.empty()){
		int i = q.front().first.first, j = q.front().first.second, minute = q.front().second;
		q.pop();
		ans = max(ans, minute);
		for(int d = 0; d < 4; d++){
			int di = dir[d].first, dj = dir[d].second;
			if(0 <= i+di && i+di <= n-1 && 0 <= j+dj && j+dj <= m-1 && !used[i+di][j+dj] && a[i+di][j+dj] == 1){
				used[i+di][j+dj] = true;
				q.push(make_pair(make_pair(i+di,j+dj), minute+1));
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 1 && !used[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;

	return 0;
}