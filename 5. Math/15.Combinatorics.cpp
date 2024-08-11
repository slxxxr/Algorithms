class Combinatorics {

public:
    
    ll get_c(ll k, ll n) { // return C(k,n) = n! / ((n-k)! * k!) , k <= n; 
        if (k > n) { return 0; }
        return ((fact[n] * inv_f[n - k]) % mod * inv_f[k]) % mod;
    }

    ll get_katalan(ll n) { // return Catalan number
        return get_c(n, 2 * n);
    }

    void build(ll _maxn, ll _mod) { // Calculate all factorials and inv. factorials, O(N)
        maxn = _maxn; mod = _mod;

        fact.assign(maxn + 1, 1);
        inv_f.assign(maxn + 1, 1);

        for (ll i = 1; i <= maxn; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        inv_f[maxn] = binpow(fact[maxn], mod - 2);
        for (ll i = maxn - 1; i >= 1; i--) {
            inv_f[i] = (inv_f[i + 1] * (i + 1)) % mod;
        }
    }

private:
    ll maxn, mod;
    vll fact, inv_f; // 1 - index, Factorial(i) = fact[i]
    
    ll binpow(ll a, ll n) {
        a %= mod;
        ll res = 1;
        while (n != 0) {
            if (n & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            n >>= 1;
        }
        return res;
    }

};
