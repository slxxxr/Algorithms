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

	ll get(ll ind) {
		ind += n - 1;
		ll res = 0;

		while (ind > 0) {
			res += tree[ind];
			ind = (ind - 1) / 2;
		}
		return res;
	}


	void update(ll l, ll r, ll value) { // [l, r) +=value
		l += n - 1;
		r += n - 1;

		while (l < r) {
			if (l % 2 == 0) {
				tree[l++] += value;
			}
			if (r % 2 == 0) {
				tree[--r] += value;
			}
			l /= 2;
			r /= 2;
		}
	}

};
