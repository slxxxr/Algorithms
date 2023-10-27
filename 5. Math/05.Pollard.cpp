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
    while (b > 0) { a %= b; swap(a, b); }
    return a;
}
ll pollard(ll n) {
    if (n % 2 == 0) { return 2; }
    auto nxt = [&](ll seed) { return sum(mul(seed, seed, n), 3, n); };
    ll x = rnd() % n;
    ll y = x;
    for (ll it = 0; it < 100000; ++it) {//с границей можно поиграть
        if (x != y && gcd(abs(x - y), n) != 1) {
            return gcd(abs(x - y), n);
        }
        x = nxt(x);
        y = nxt(nxt(y));
    }
    return 1;
}
void factorize_sqrt(ll x, unordered_map<ll, ll>& divisors) {
    for (ll i = 2; i * i <= x;) {
        if (x % i == 0) {
            divisors[i]++;
            x /= i;
        }
        else { i++; }
    }
    if (x > 1) { divisors[x]++; }
}
void factorize(ll n, unordered_map<ll,ll>& divisors) {//map делителей: ключ - простой делитель, значение ключа - степень вхождения простого делителя
	if (n == 1) { return; }
    if (n < 1e12) {
        factorize_sqrt(n, divisors);
        return;
    }
	queue<ll> que;
	que.push(n);
	while (!que.empty()) {
		ll now = que.front();
		que.pop();
		if (now == 1) continue;
		bool prime = true;
		ll tmp;
		forn(i, 5) {//с границей можно поиграть
			tmp = pollard(now);
            if (tmp != now and tmp != 1) { prime = false; break; }
		}

		if (prime) { divisors[now]++; }
        else {
            if (now / tmp < 1e9) { factorize_sqrt(now / tmp, divisors); }//с границей можно поиграть
            else { que.push(now / tmp); }
            if (tmp < 1e9) { factorize_sqrt(tmp, divisors); }
            else { que.push(tmp); }
        }
	}
}
