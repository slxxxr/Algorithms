struct SegmentTree {
 
	struct node {
		ll pref, suf, seg, sum;
	};
 
	node comb(node l, node r) {
		node result;
 
		result.seg = max(max(l.seg, r.seg), l.suf + r.pref);
		result.pref = max(l.pref, l.sum + r.pref);
		result.suf = max(r.suf, r.sum + l.suf);
		result.sum = l.sum + r.sum;
 
		return result;
	}
 
	const node zero = { 0,0,0,0 };
 
 
	vector< node > tree;
	ll n = 1;
 
	void build(vll& arr) {
		while (n < arr.size()) n *= 2;
		tree.assign(2 * n - 1, zero);
 
		for (ll i = 0; i < arr.size(); i++) {
			tree[n + i - 1] = { arr[i],arr[i],arr[i],arr[i] };
		}
 
		for (ll i = n - 2; i >= 0; i--) {
			tree[i] = comb(tree[i * 2 + 1], tree[i * 2 + 2]);
		}
	}
 
	void update(ll i, ll x) {//изменение в точке
		i += n - 1;
		tree[i] = { x,x,x,x };
 
		while (i > 0) {
			--i /= 2;
			tree[i] = comb(tree[2 * i + 1], tree[2 * i + 2]);
		}
	}
 
	ll max_seg() { return max(tree[0].seg, (ll)0); }
 
};
