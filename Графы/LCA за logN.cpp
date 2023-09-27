
ll n, m, timer = 0;
ll l = 1; //log(n)
vector<vll> gr, up;
vll tin, tout;


void dfs_lca(ll v, ll p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;

    for (ll i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    
    for (ll u : gr[v]) {
        if (u != p)
            dfs_lca(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(ll a, ll b) {//проверка a это предок b?
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

ll lca(ll a, ll b) {
    if (is_ancestor(a, b))  return a;
    if (is_ancestor(b, a))  return b;
    for (ll i = l; i >= 0; --i)
        if (!is_ancestor(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    up.assign(n, vll(l + 1));
    while ((1LL << l) <= n)l++;
    dfs_lca(root);
}
