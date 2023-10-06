ll binpow(ll a, ll n) {
    ll res = 1;
    while (n != 0) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
