
string s;

int prefix_func[s.size()];

prefix_func[0] = 0;
									// aabaab
for(int i = 1; i < s.size(); i++){   // i = 4 d = 2 
	for(int d = 0; d <= i; d++){
		if(s.substr(0,d) == s.substr(i-d+1, d)){
			prefix_func[i] = d;
		}
	}
}

