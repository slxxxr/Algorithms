class segtree {
private:

	struct node { // вынести в глобал, если нужно
		ll suma;
	};

	const node zero = { 0 };

	node comb(node& a, node& b) {
		node res = zero;
		res.suma = a.suma + b.suma;
		return res;
	}

	vector<node> tree;
	ll n = 1;

public:

	segtree(vll& arr) {
		while (n < (ll)arr.size()) { n *= 2; }
		//n = arr.size();
		tree.assign(2 * n - 1, zero);

		for (ll i = 0; i < (ll)arr.size(); i++) {
			tree[n + i - 1] = { arr[i] };
		}
		for (ll i = n - 2; i >= 0; i--) {
			tree[i] = comb(tree[i * 2 + 1], tree[i * 2 + 2]);
		}
	}

	segtree(ll _N, ll _value) {
		while (n < _N) { n *= 2; }
		//n = _N;
		tree.assign(2 * n - 1, zero);

		for (ll i = 0; i < _N; i++) {
			tree[n + i - 1] = { _value };
		}
		for (ll i = n - 2; i >= 0; i--) {
			tree[i] = comb(tree[i * 2 + 1], tree[i * 2 + 2]);
		}
	}

	void update(ll ind, ll NewValue) { // arr[ind] = NewValue, 0-index
		ind += n - 1;
		tree[ind] = { NewValue };

		while (ind > 0) {
			ind = (ind - 1) / 2;
			tree[ind] = comb(tree[2 * ind + 1], tree[2 * ind + 2]);
		}
	}


	ll sum(ll l, ll r) {// sum[l, r], 0-index
		l += n - 1;
		r += n;
		node res = zero;

		while (l < r) {
			if (l % 2 == 0) {
				res = comb(res, tree[l++]);
			}
			if (r % 2 == 0) {
				res = comb(res, tree[--r]);
			}
			l /= 2;
			r /= 2;
		}
		return res.suma;
	}

};
