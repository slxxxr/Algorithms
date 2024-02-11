const int maxn = 1e5;
set<int> g[maxn];

void euler(int v) {
    while (!g[v].empty()) {
        u = *g[v].begin();
        g[v].erase(u);
        g[u].erase(v); // если граф ориентированный, обратное ребро удалять не надо
        euler(u);
    }
    cout << v <<  " ";
}
