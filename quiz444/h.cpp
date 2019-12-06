#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>


using namespace std;



int main(){
	

	int t;
	cin >> t;
	while(t--){

		map<char, int> cnt;
		cnt.clear();
		queue<char> q;
		while(!q.empty()) q.pop();		

		int n;
		cin >> n;

		for(int i = 0; i < n; i++){
			char ch;
			cin >> ch;
			if(cnt[ch] == 0){
				cout << ch << " ";
				cnt[ch]++;
				q.push(ch);
			}else{
				cnt[ch]++;
				while(!q.empty() && cnt[q.front()] > 1){
					q.pop();
				}
				if(!q.empty()){
					cout << q.front() << " ";
				}else{
					cout << -1 << " ";
				}
			}
		}
		cout << endl;

	}
	return 0;
}