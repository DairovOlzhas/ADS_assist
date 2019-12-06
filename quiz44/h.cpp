#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <stdio.h>
#include <utility> 
#include <sstream>   
using namespace std;

int a[110][110];
int n,m;

void bfs(int i, int j){
    if(0 <= i && i <= n-1 && 0 <= j && j <= m-1 && a[i][j] == 1){
        a[i][j] = 2;
        bfs(i-1,j);
        bfs(i+1,j);
        bfs(i,j+1);
        bfs(i,j-1);
    }

}
  
int main() 
{ 
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = int(s[j]-'0');
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                bfs(i,j);
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0; 
} 