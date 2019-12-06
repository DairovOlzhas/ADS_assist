#include <iostream>
#include <vector>
#include <set>
using namespace std;


long long pow[10000];
long long p = 29;
long long m = 1000000000;

void power(){
  pow[0] = 1;
  for(int i = 1; i < 10000; i++){
    pow[i] = (pow[i-1]*p)%m;
  }
}


long long hashForT(string t){
  
  long long hash = t[0]-'a';

  for(int i = 1; i < t.size(); i++){
    hash += ((t[i]-'a')*pow[i])%m;
  }
  return hash;
}

vector<long long> hashForS(string s){
  vector<long long> hash_s(s.size());

  for(int i = 0; i < s.size(); i++){
    if(i == 0) hash_s[i] = s[i]-'a';
    else
      hash_s[i] = hash_s[i-1] + (s[i]-'a')*pow[i];
  }
  return hash_s;
}
int main(){
  
    

  string s,t;
  cin >> s >> t;
 
  power();

  vector<long long> hash_s;

  hash_s = hashForS(s);
  set<string> ans;
  for(int i = 1; i <= t.size(); i++){
    for(int k = 0; k <= t.size()-i; k++){
      string tt = t.substr(k,i);
      bool same = false;
      long long hash_tt = hashForT(tt);


      for(int j = 0; j < s.size()-tt.size()+2; j++){
        int l = max(0, j-1);
        int r = j+tt.size()-1;
        if((j == 0 && hash_s[r] == hash_tt) || ((hash_s[r]-hash_s[l])/pow[j] == hash_tt)){
          same = true;
          break;
        }
      

      }

      if(same)
        ans.insert(tt);
    }
  }

  cout << ans.size();
  
  
  return 0;
}