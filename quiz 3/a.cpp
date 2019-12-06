#include <iostream>
#include <vector>

using namespace std;




int main(){
  
  

  string s,t;
  cin >> s >> t;

  vector<int> ans;
  string a = t+" "+s;
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
    if(p[i] >= t.size()){
      ans.push_back(i-2*t.size());
    }
  }
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";    
  }
  return 0;
}