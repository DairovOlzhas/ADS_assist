
#include <iostream>
#include <vector>

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
  hash_s[0] = 0;

  for(int i = 0; i < s.size(); i++){
    if(i == 0) hash_s[i] = s[i]-'a';
    else
      hash_s[i] = hash_s[i-1] + (s[i]-'a')*pow[i];
  }
  return hash_s;
}
int main(){
  
    

  string s;
  cin >> s;
 
  power();

  std::vector<long long> hash_s;

  hash_s = hashForS(s);

  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    string t;
    cin >> t;
    bool ans = false;
    long long hash_t = hashForT(t);


    for(int j = 0; j < s.size()-t.size()+2; j++){
      int l = max(0, j-1);
      int r = j+t.size()-1;
      if((j == 0 && hash_s[r] == hash_t) || ((hash_s[r]-hash_s[l])/pow[j] == hash_t)){
        ans = true;
        break;
      }
    

    }

    if(ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

  }
  
  
  return 0;
}