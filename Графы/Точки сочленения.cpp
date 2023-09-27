ll n, m;
vector<vll> gr;
vll used, h, d;

/*
gr.resize(n);
used.assign(n,0);
h.assign(n,0);
d.assign(n,0);
*/

void dfs(ll v, ll p = -1) {
    used[v] = 1;
    d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
    ll children = 0;
    for (ll u : gr[v]) {
        if (u != p) {
            if (used[u]) {
                d[v] = min(d[v], h[u]);
            }
            else {
                dfs(u, v);
                d[v] = min(d[v], d[u]);
                if (h[v] <= d[u] && p != -1) {
                    // v -- точка сочленения
                    // (это условие может выполниться много раз для разных детей)
                }
                children++;
            }
        }
    }
    if (p == -1 && children > 1) {
        // v -- корень и точка сочленения
    }
}
