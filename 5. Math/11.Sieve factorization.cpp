const int N = 1e5;
vector<ll> lp(N + 1, 0), pr;

void sieve() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

unordered_map<ll, ll> fact(ll n) { // O(logN)
    unordered_map<ll, ll> divs;
    while (n != 1) {
        divs[lp[n]]++;
        n /= lp[n];
    }

    return divs;
}
