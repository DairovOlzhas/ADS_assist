#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <utility> 
#include <sstream>   
using namespace std;


int cntIn(string t, string s){
    string a = t + "#" + s;

    vector<int> p(a.size());
    p[0] = 0;

    for(int i = 1; i < p.size(); i++){
        int j = p[i-1];
        while(j > 0 && a[j] != a[i])
            j = p[j-1];
        if(a[j] == a[i])
            j++;
        p[i] = j;
    }
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(p[i] == t.size())
            cnt++;
    }
    return cnt;
}
  
int main() 
{ 
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;

        v.push_back(s);
    }

    string a;
    cin >> a;
    int mx = 0;
    vector<string> ans;
    for (int i = 0; i < n; ++i){
        int cnt = cntIn(v[i], a);
        if(cnt > mx){
            ans.clear();
            ans.push_back(v[i]);
            mx = cnt;
        }else if(cnt == mx){
            ans.push_back(v[i]);
        }
    }
    cout << mx << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0; 
} 