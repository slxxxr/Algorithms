class Combinatorics {
private:
    ll _maxn, _mod;
    vector<ll> _fact, _inv_f; // 1 - index, Factorial(i) = fact[i]

public:

    ll get_c(int k, int n) { // return C(k,n) = n! / ((n-k)! * k!); O(1)
        if (k > n) { return 0; }
        return ((_fact[n] * _inv_f[n - k]) % _mod * _inv_f[k]) % _mod;
    }

    ll get_catalan(int n) { // return Catalan number, O(1)
        return get_c(n, 2 * n);
    }

    Combinatorics(ll maxn, ll mod) { // Calc all factorials and inv. factorials; O(N)
        _maxn = maxn; _mod = mod;
        _fact.assign(maxn + 1, 1);
        _inv_f.assign(maxn + 1, 1);

        for (ll i = 1; i <= maxn; i++) {
            _fact[i] = (_fact[i - 1] * i) % mod;
        }

        _inv_f[maxn] = binpow(_fact[maxn], mod - 2); // if mod is prime
        for (ll i = maxn - 1; i >= 1; i--) {
            _inv_f[i] = (_inv_f[i + 1] * (i + 1)) % mod;
        }
    }

    ll binpow(ll a, ll n) {
        a %= _mod;
        ll res = 1;
        while (n != 0) {
            if (n & 1) {
                res = (res * a) % _mod;
            }
            a = (a * a) % _mod;
            n >>= 1;
        }
        return res;
    }
};
