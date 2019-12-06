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

    void insert(string s){
        Node *cur = root;
        for(int i = 0; i < s.size(); i++){
            if(cur->ch[s[i]-'0'] == NULL){
                Node *node = new Node();
                cur->ch[s[i]-'0'] = node;
                cur = node;
            }else{
                cur = cur->ch[s[i]-'0'];
            }
        }
        cur->isEnd = true;
    }

    bool find(string s){
        Node *cur = root;
        for(int i = 0; i < s.size(); i++){
            if(cur->isEnd) return true;
            if(cur->ch[s[i]-'0'] == NULL) return false;
            cur = cur->ch[s[i]-'0'];
        }
        return false;
    }


};
  
int main() 
{ 
    int n, m;
    cin >> n >> m;
    Trie *trie = new Trie();
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        trie->insert(s);
    }

    for(int i = 0; i < m; i++){
        string s;
        cin >> s;

        if(trie->find(s)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }

    return 0; 
} 