#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <utility> 
#include <sstream>   
using namespace std;


int prefix_func(string t, string s){
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
    return p[p.size()-1];
}

string toLowerCase(string s){
    string res = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            res += char('a'+(s[i]-'A'));
        }else
            res += s[i];
    }
    return res;
}

string toUpper(string s){
    string res = "";
    res += char('A'+(s[0]-'a')) + s.substr(1);
    return res;
}
  
int main() 
{ 
    string p;
    cin >> p;
    p = toLowerCase(p);
    int n;
    cin >> n;
    vector<string> t;
    for(int i = 0; i < n; i++){
        string tt;
        cin >> tt;
        tt = toLowerCase(tt);
        t.push_back(tt);
    }
    int mx = 0;
    vector<string> ans;

    for(int i = 0; i < n; i++){
        int pr = prefix_func(t[i], p);
        if(mx < pr){
            ans.clear();
            ans.push_back(t[i]);
            mx = pr;
        }else if(mx == pr && pr != 0){
            ans.push_back(t[i]);
        }
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << toUpper(ans[i]) << endl;
    }
    return 0; 
} 