struct segtree {
 
	vector<ll> tree;
	ll n = 1;
 
	void build(vll& arr) {
		while (n < arr.size()) { n *= 2; }
		//n = arr.size();
		tree.assign(2 * n - 1, 0);
 
		for (ll i = 0; i < arr.size(); i++) {
			tree[n + i - 1] = arr[i];
		}
		for (ll i = n - 2; i >= 0; i--) {
			tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
		}
	}
 
	void update(ll ind, ll NewValue) { // 0-index
		ind += n - 1;
		tree[ind] = NewValue;
 
		while (ind > 0) {
			ind = (ind - 1) / 2;
			tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
		}
	}
 
 
	ll sum(ll l, ll r) {// sum[l, r) 0-index
 
		l += n - 1;
		r += n - 1;
		ll result = 0;
 
		while (l < r) {
			if (l % 2 == 0) {
				result += tree[l++];
			}
			if (r % 2 == 0) {
				result += tree[--r];
			}
			l /= 2;
			r /= 2;
		}
		return result;
	}
 
};
