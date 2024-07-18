struct Fenwick {
    ll n;
    vll tree;

    void build(vll& arr) { // O(N*logN)
        n = (ll)arr.size();
        tree.assign(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            update(i - 1, arr[i - 1]);
        }
    }

    ll get_sum(ll ind) { // 0 - index
        ll res = 0;
        for (ll i = ind + 1; i > 0; i -= i & (-i)) {
            res += tree[i];
        }
        return res;
    }

    ll get_sum(ll l, ll r) { // 0 - index, return (arr[l] + arr[l + 1] + arr[l + 2] + ... + arr[r - 2] + arr[r - 1] + arr[r]), O(logN)
        return (get_sum(r) - get_sum(l - 1));
    }

    void update(ll ind, ll val) { // 0 - index, arr[ind] += val, O(logN)
        for (ll i = ind + 1; i <= n; i += i & (-i)) {
            tree[i] += val;
        }
    }
};
