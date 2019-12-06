#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>



using namespace std;

int parent[100100];
int sz[100100];

void make_set(int v){
	parent[v] = v;
	sz[v] = 1;
}

int get_parent(int v){
	if(parent[v] == v) return v;
	return parent[v] = get_parent(parent[v]);
}

bool union_set(int a, int b){
	a = get_parent(a);
	b = get_parent(b);

	if(a != b){
		if(sz[a] > sz[b])
			swap(a,b);

		parent[a] = b;
		sz[b] += sz[a];
		return true;
	}
	return false;
}


int main(){
	
	int n;
	cin >> n;
	int a[n][n];

	for(int i = 0 ; i < n; i++){
		make_set(i);
	}

	vector<pair<int, pair<int,int> > > edges;

	for(int i = 0;  i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(j > i){
				if(a[i][j] == 0){
					union_set(i,j);
				}else{
					edges.push_back({a[i][j], {i,j}});
				}
			}
		}
	}

	int ans = 0;

	sort(edges.begin(), edges.end());

	for(int i = 0; i < edges.size(); i++){
		int w = edges[i].first, a = edges[i].second.first, b = edges[i].second.second;
		if(union_set(a,b)){
			ans += w;
		}
	}

	cout << ans;

	return 0;
}