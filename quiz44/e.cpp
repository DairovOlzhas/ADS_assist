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
    Node *ch[26];
    int cnt;
    Node(){
        cnt = 1;
        for(int i = 0; i < 26; i++){
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

    void insert(string s){
        Node *cur = root;
        for(int i = 0; i < s.size(); i++){
            if(cur->ch[s[i]-'a'] == NULL){
                Node *node = new Node();
                cur->ch[s[i]-'a'] = node;
                cur = node;
            }else{
                cur = cur->ch[s[i]-'a'];
                cur->cnt++;
            }
        }
    }

    int find(string s){
        Node *cur = root;
        for(int i = 0; i < s.size(); i++){
            if(cur->ch[s[i]-'a'] == NULL){
                return 0;
            }else{
                cur = cur->ch[s[i]-'a'];
            }
        }
        return cur->cnt;
    }

};
  
int main() 
{ 
    int n,q;
    cin >> n >> q;
    Trie* trie = new Trie();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        trie->insert(s);
    }

    for(int i = 0; i < q; i++){
        string s;
        cin >> s;
        cout << trie->find(s) << endl;
    }
    return 0; 
} 