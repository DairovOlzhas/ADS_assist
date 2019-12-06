#include <iostream>
#include <vector>
#include <map>
#include <algorithm>



using namespace std;

int parent[100000];

void make_set(int v){
	parent[v] = v;
}

int get_parent(int v){
	if(parent[v] == v) return v;
	return parent[v] = get_parent(parent[v]);
}

bool union_set(int a, int b){	
	a = get_parent(a);
	b = get_parent(b);

	if(a != b){
		parent[a] = b;
		return true;
	}	

	return false;
}


int main(){
	
	int n;
	cin >> n;

	int a[n][n];
	
	for(int i = 0; i < n; i++){
		make_set(i);
	}
	

	vector<pair<int, pair<int,int> > > edges;
	

	for(int i= 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(j > i){
				if(a[i][j] != 0){
					edges.push_back({a[i][j],{i,j}});				
				}else{
					union_set(i,j);
				}
			}
		}
	}

	sort(edges.begin(), edges.end());

	int ans = 0;
	
	for(int i = 0; i < edges.size(); i++){
		if(union_set(edges[i].second.second,edges[i].second.first)) ans+=edges[i].first;
	}

	cout << ans;

	return 0;
}