vector<vector<pair<ll, ll>>> gr;

vector<ll> dijkstra(int s) {
    ll n = gr.size();
    vector<ll> d(n, inf), p(n, -1);

    d[s] = 0;
    set<pair<ll, ll>> q;
    q.insert({ 0, s });
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : gr[v]) {
            ll to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({ d[to], to });
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({ d[to], to });
            }
        }
    }

    return d;
}
