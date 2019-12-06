#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <utility> 
#include <sstream>   
using namespace std;


int cntIn(string s){
    string a = s;

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
  
int main() 
{ 
    string s;
    cin >> s;

    cout << s.size()-cntIn(s);
    return 0; 
} 