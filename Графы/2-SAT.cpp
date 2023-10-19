ll n, m, cnt_perem;
vector<vector<ll>> gr, gr_obr;
vll used, order, comp;

void top_sort(ll v) {
    used[v] = 1;
    for (ll u : gr[v]) {
        if (!used[u]) top_sort(u);
    }
    order.pb(v);
}

void paint(ll v, ll color) {
    comp[v] = color;
    for (ll u : gr_obr[v]) {
        if (comp[u] == -1) paint(u, color);
    }
}


void create_obr() {
    gr_obr.resize(2 * cnt_perem);
    for (ll i = 0; i < 2 * cnt_perem; i++) {
        for (ll j : gr[i]) {
            gr_obr[j].pb(i);
        }
    }
}

void find_sort() {
    used.assign(2 * cnt_perem, 0);
    for (ll i = 0; i < 2 * cnt_perem; i++) {
        if (!used[i]) top_sort(i);
    }
    reverse(all(order));
}

void paint_comp() {
    ll color = 0;
    comp.assign(2 * cnt_perem, -1);
    for (ll i : order) {
        if (comp[i] == -1) paint(i, color++);
    }
}

void solve_2sat() {
    create_obr();
    find_sort();
    paint_comp();
    //Если comp[a]==comp[a+cnt_perem] ==> нет решения
}
