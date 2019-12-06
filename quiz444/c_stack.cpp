#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>


using namespace std;



int main(){
	
	string s;
	cin >> s;

	stack<char> st;

	for(int i = 0 ; i < s.size(); i++){
		if(st.empty()){
			st.push(s[i]);
		}else if(st.top() == s[i]){
			st.pop();
		}else{
			st.push(s[i]);
		}
	}

	if(st.empty()){
		cout << "YES";
	}else{
		cout << "NO";
	}


	int balance = 0;
	for(int i = 0 ; i < s.size(); i++){
		if(s[i] == '(') balance++;
		else balance--;
		if(balance < 0){
			cout << "NO";
			return 0;
		}
	}
	if(balance == 0){
		cout << "YES";
	}else{
		cout << "NO";
	}

	return 0;
}