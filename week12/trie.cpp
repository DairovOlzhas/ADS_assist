#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <stdio.h>
#include <utility> 
#include <sstream>   
using namespace std;


class Node{
public:
    Node *ch[10];
    bool isEnd;
    Node(){
        isEnd = false;
        for(int i = 0; i < 10; i++){
            ch[i] = NULL;
        }
    }
};

class Trie{
    public:
    Node * root;

    Trie(){
        root = new Node();
    }

    bool inserted(string s){
        Node *cur = root;
        bool added = false;
        for(int i = int(s.size()-1); i >= 0; i--){
            if(cur->isEnd) return false;
            if(cur->ch[s[i]-'0'] == NULL){
                Node *node = new Node();
                cur->ch[s[i]-'0'] = node;
                cur = node;
                added = true;
            }else{
                cur = cur->ch[s[i]-'0'];
            }
        }

        if(!added) return false;

        cur->isEnd = true;
        return true;
    }

};
  
int main() 
{ 
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;

        Trie *trie = new Trie();

        vector<string> numbers;
        for(int j = 0; j < m; j++){
            string s;
            cin >> s;
            numbers.push_back(s);
        }

        bool isp = true;
        for(int j = 0; j < m; j++){
            if(!trie->inserted(numbers[j])){
                isp = false;
                break;
            }
        }

        if(isp)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0; 
} 