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
    Node* ch[10];
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

    Node* root;

    Trie(){
        root = new Node();
    }

    bool inserted(string s){
        Node* cur = root;

        for(int i = s.size()-1; i >= 0; i--){
            if(cur->isEnd) return false;
            if(cur->ch[s[i]-'0'] == NULL){
                Node * node = new Node();
                cur->ch[s[i]-'0'] = node;
                cur = node;
            }else{
                cur = cur->ch[s[i]-'0'];
            }
        }
        cur->isEnd = true;
        return true;
    }

};
  
int main() 
{ 
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        Trie *trie = new Trie();
        vector<string> nums;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            nums.push_back(s);
        }
        bool haveProb = false;
        for(int i = 0; i < n; i++){
            if(!trie->inserted(nums[i])){
                haveProb = true;
                // cout << nums[i] << endl;
                break;
            }
        }

        if(!haveProb)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0; 
} 