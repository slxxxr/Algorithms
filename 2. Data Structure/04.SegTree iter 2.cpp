struct segtree {

	struct node {
		ll suma;
	};

	const node zero = { 0 };

	node comb(node& a, node& b) {
		node res = zero;
		res.suma += a.suma + b.suma;
		return res;
	}

	vector<node> tree;
	ll n = 1;

	void build(vll& arr) {
		while (n < (ll)arr.size()) { n *= 2; }
		//n = arr.size();
		tree.assign(2 * n - 1, zero);

		for (ll i = 0; i < arr.size(); i++) {
			tree[n + i - 1] = { arr[i] };
		}
	}

	ll get(ll ind) { //0-index
		ind += n - 1;
		node res = tree[0];

		while (ind > 0) {
			res = comb(res, tree[ind]);
			ind = (ind - 1) / 2;
		}
		return res.suma;
	}


	void update(ll l, ll r, ll value) { // [l, r] +=value 0-index
		l += n - 1;
		r += n;

		node NewValue = { value };

		while (l < r) {
			if (l % 2 == 0) {
				tree[l] = comb(tree[l], NewValue);
				l++;
			}
			if (r % 2 == 0) {
				r--;
				tree[r] = comb(tree[r], NewValue);
			}
			l /= 2;
			r /= 2;
		}
	}

};
