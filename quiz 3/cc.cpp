#include <iostream>
#include <vector>
#include <set>
using namespace std;


long long pow_p[10000];
long long p = 29;
long long mod = 1000000000;

void calcPowP(){
  pow_p[0] = 1;
  for(int i = 1; i < 10000; i++){
    pow_p[i] = (pow_p[i-1]*p)%mod;
  }
}


long long hash_string(string t){
  
  long long hash = t[0]-'a';

  for(int i = 1; i < t.size(); i++){
    hash += ((t[i]-'a')*pow_p[i])%mod;
  }
  return hash;
}


int main(){
  
    

  string s,tt;
  cin >> s >> tt;
  long long hash_s[s.size()];
  hash_s[0] = 0;
  calcPowP();

  for(int i = 0; i < s.size(); i++){
    if(i == 0) hash_s[i] = s[i]-'a';
    else
      hash_s[i] = hash_s[i-1] + (s[i]-'a')*pow_p[i];
  }

  set<string> res;
  
  for(int i = 1; i <= tt.size(); i++){
    for(int k = 0; k <= tt.size()-i; k++){
      string t = tt.substr(k,i);
      bool ans = false;
      long long hash_t = hash_string(t);


      for(int j = 0; j < s.size()-t.size()+2; j++){
        int l = max(0, j-1);
        int r = j+t.size()-1;
        if((j == 0 && hash_s[r] == hash_t) || ((hash_s[r]-hash_s[l])/pow_p[j] == hash_t)){
          ans = true;
          break;
        }
      

      }

      if(ans)
        res.insert(t);
    }
  }

  cout << res.size();
  
  
  return 0;
}