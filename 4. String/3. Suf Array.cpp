vector<ll> suf_mas(string s) {
    s = s + "$";
    ll n = size(s);
    vector<ll> p;
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int a, int b) {return s[a] < s[b]; });
    vector<pair<ll, ll>> classes(n);
    for (int i = 0, nxt = 0; i < n; i++) {
        classes[p[i]] = { nxt, -1 };
        if (i + 1 < n and s[p[i + 1]] != s[p[i]]) nxt++;
    }
    vector<pair<ll, ll>> classes2(n);
    for (int sz0 = 1, sz = 2; sz0 < n; sz0 *= 2, sz *= 2) {
        for (int i = 0; i < n - 1; i++) {
            classes[i].second = classes[(i + sz0) % n].first;
        }
        sort(p.begin(), p.end(), [&](int a, int b) {return classes[a] < classes[b]; });
        for (int i = 0, nxt = 0; i < n; i++) {
            classes2[p[i]] = { nxt, -1 };
            if (i + 1 < n and classes[p[i + 1]] != classes [p[i]] ) nxt++;
        }
        swap(classes, classes2);
    }
    return p;
}
