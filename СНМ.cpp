vector<int> p, s;

int leader(int v) {
    return (p[v] == v) ? v : p[v] = leader(p[v]);
}

void unite(int a, int b) {
    a = leader(a), b = leader(b);
    if (s[a] > s[b])
        swap(a, b);
    s[b] += s[a];
    p[a] = b;
}

void init(int n) {
    p.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++)
        p[i] = i, s[i] = 1;
}
