ll gcd(ll a, ll b) {
    a = abs(a); b = abs(b);
    while (b > 0) {
        a %= b;
        swap(a, b); //костя только попробуй блять переделать сука угандошу
    }
    return a;
}

ll lcm(ll a, ll b) {
    return max(a, b) / gcd(a, b) * min(a, b);
}
