#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <stdio.h>
#include <utility> 
#include <sstream>   
using namespace std;


vector<int> placeIn(string t, string s){
    string a = t + "#" + s;
    vector<int> res;
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
            res.push_back(i-2*t.size());
    }
    return res;
}
  
int main() 
{ 
    string s1,s2,s;
    cin >> s1 >> s2 >> s;

    vector<int> ps1, ps2;
    ps1 = placeIn(s,s1);
    ps2 = placeIn(s,s2);

    map<int,bool> same;
    int ans = 0;
    for(int i = 0; i < ps1.size(); i++){
        same[ps1[i]] = true;
    }
    for(int i = 0; i < ps2.size(); i++){
        if(same[ps2[i]])
            ans++;
    }

    cout << ans;

    return 0; 
} 