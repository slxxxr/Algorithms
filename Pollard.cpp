mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll sum(ll x, ll y, ll mod) { return x + y < mod ? x + y : x + y - mod; }
ll mul(ll x, ll y, ll mod) {
    ll res = 0;
    while (y) {
        if (y & 1) {
            res = sum(res, x, mod);
        }
        x = sum(x, x, mod);
        y >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll pollard(ll n) {
    if (n % 2 == 0) {
        return 2;
    }
    auto nxt = [&](ll seed) { return sum(mul(seed, seed, n), 3, n); };
    ll x = rnd() % n;
    ll y = x;
    for (ll it = 0; it < 1e6; ++it) {//можно поиграться с границей
        if (x != y && gcd(abs(x - y), n) != 1) {
            return gcd(abs(x - y), n);
        }
        x = nxt(x);
        y = nxt(nxt(y));
    }
    return -1;
}
