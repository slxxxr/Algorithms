const ll maxn = 1e5;
vector<set<ll>> gr(maxn);

void euler(ll v) {
    while (!gr[v].empty()) {
        ll u = *gr[v].begin();
        gr[v].erase(u);
        gr[u].erase(v); // если граф ориентированный, обратное ребро удалять не надо
        euler(u);
    }
    cout << v <<  " ";
}
