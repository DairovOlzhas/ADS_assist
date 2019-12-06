#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>


using namespace std;

bool prefix(string s, string t){
	string a = t+"#"+s;
	vector<int> p(a.size());
	p[0] = 0;
	for(int i = 1; i < a.size(); i++){
		int j = p[i-1];
		while(j > 0 && a[i] != a[j]){
			j = p[j-1];
		}
		if(a[i] == a[j]) j++;
		p[i] = j;
	}

	for(int i = t.size(); i < a.size(); i++){
		if(p[i] == t.size()) return true;
	}
	return false;

}

int main(){
	

	string a,b;
	cin >> a >> b;

	if(a.size() >= b.size()){
		if(prefix(a,b)){
			cout << 1;
		}else if(prefix(a+a, b)){
			cout << 2;
		}else{
			cout << -1;
		} 
	}else{
		string new_a = "";
		int n = (b.size()+a.size()-1)/a.size();
		for(int i = 0; i < n; i++){
			new_a+=a;
		}
		if(prefix(new_a,b)){
			cout << n;
		}else if(prefix(new_a+a, b)){
			cout << n+1;
		}else{
			cout << -1;
		}
	}

	return 0;
}