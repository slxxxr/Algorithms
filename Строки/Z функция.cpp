vector<int> z(string s) {
	vector<int> ans = { 0 };
	int l = 0, r = 0, a = 0;
	for (int i = 1; i < size(s); i++) {
		a = 0;
		if (i <= r) {
			a = min(ans[i-l],(int)r - i);
		}
		while (s[i + a] == s[a] && i+ a< size(s)) {
			a++;
		}
		if (i+ a > r) {
			r = min(i + a - 1,(int) size(s) - 1);
			l = i;
			
		}
		ans.push_back(min(a,(int) size(s)-1));
	}
	return ans;
}
