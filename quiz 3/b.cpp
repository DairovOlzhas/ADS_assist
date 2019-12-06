
#include <iostream>
#include <vector>

using namespace std;

int prefix_func(string s, string t){
	
}


int main(){
  
  

  string s,t;
  cin >> s >> t;

    string a = t+s;
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

  int ans1 = p[p.size()-1];


    a = s+t;
    p[0] = 0;
    for(int i = 1; i < a.size(); i++){
      int j = p[i-1];
      while(j > 0 && a[i] != a[j]){
        j = p[j-1];
      }
    if(a[i] == a[j]) j++;
      p[i] = j;
  }

  int ans2 = p[p.size()-1];


  cout << max(ans1, ans2);
  
  
  return 0;
}