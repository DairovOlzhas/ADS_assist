

vector<int> notsame(vector<int> a, vector<int> b){
	int p1 = 0, p2 = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> res;

	while(p1 < a.size() && p2 < b.size()){
		while(p2 < b.size() && b[p2] < a[p1]) p2++;
		if(p2 < b.size() && b[p2] == a[p1]) p1++;
		else if(p2 < b.size() && b[p2] > a[p1]) {
			res.push_back(a[p1]);
			p1++;
		}
	}
}