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
//-----------------------------------------

vector <int> p(n);
vector <int> size_set(n, 1);
int get(int x) {
    if (p[x] != x) p[x] = get(p[x]);
    return p[x];
}


void union_set(int x, int y) {
    x = get(x); y = get(y);
    if (size_set[y] < size_set[x]) swap(x, y);
    p[x] = y;
    size_set[y] += size_set[x];
    //size_set[y] = size_set[x];
}
