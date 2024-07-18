vll all_phi(ll n) {// Calculate all phi from 1 to N, O(N*log(logN))
    vector<ll> phi(n + 1);
    for (ll i = 0; i <= n; i++) {
        phi[i] = i;
    }

    for (ll i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (ll j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    return phi;
}

ll calc_phi(ll n) { // Calculate phi(n), O(sqrt(N))
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

/*
a^phi(m) == 1(mod m) if gcd(a,m) == 1, ==> a^(phi(m)-1) - обратный элемент к a
*/
