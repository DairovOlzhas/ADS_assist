#include <iostream>
#include <vector>
#include <map>



using namespace std;

long long mod;

string get_h(string s){

	long long p = 11;
	long long h = 0;
	long long pow = 1ll;
	long long n = s.size();
	string res;
	for(long long i = 0; i < n; i++){
		h += ((s[i]-47)*pow)%mod;
		h %= mod;
		pow = (pow*p)%mod;
	}
	res = to_string(h);
	return res;
}


int main(){
	
	long long n;
	
	cin >> n;
	mod = 1e9+7;
	n *= 2;

	map<string,bool> hs;
	

	vector<string> s;
	
	for(long long i = 0; i < n; i++){
		string a;
		cin >> a;
		s.push_back(a);
		hs[a] = true;
	}

	vector<pair<string,string> > ans;

	for(long long i = 0; i < n; i++){
		string h = get_h(s[i]);
		if(hs[h]){
			ans.push_back({s[i],h});
		}
	}




	for(long long i = 0; i < n/2; i++){
		cout << "h of string \"" << ans[i].first << "\" is " << ans[i].second << endl;
	}



	return 0;
}