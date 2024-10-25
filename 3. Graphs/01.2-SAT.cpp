/* a xor b = (a or b) and (!a or !b) = (!a->b) and (!b->a) and (a->!b) and (b->!a)
a or b = (!a->b) and (!b->a)
a and b = (a or b) and (a or !b) and (!a or b) = (!a->b) and (!b->a) and (!a->!b) and (b->a) and (a->b) and (!b->!a)
!(a xor b) = (a or !b) and (!a or b) = (!a->!b) and (b->a) and (a->b) and (!b->!a)
!(a and b) = (!a or !b) = (a->!b) and (b->!a)
!(a or b) = (a or !b) and (!a or b) and (!a or !b) = (!a->!b) and (b->a) and (a->b) and (!b->!a) and (a->!b) and (b->!a) */

int n, m, cnt_perem;
vector<vector<int>> gr, gr_obr;
vector<int> used, order, comp;

void top_sort(int v) {
    used[v] = 1;
    for (int u : gr[v]) {
        if (!used[u]) top_sort(u);
    }
    order.pb(v);
}

void paint(int v, int color) {
    comp[v] = color;
    for (int u : gr_obr[v]) {
        if (comp[u] == -1) paint(u, color);
    }
}

void create_obr() {
    gr_obr.resize(2 * cnt_perem);
    for (int i = 0; i < 2 * cnt_perem; i++) {
        for (int j : gr[i]) {
            gr_obr[j].pb(i);
        }
    }
}

void find_sort() {
    used.assign(2 * cnt_perem, 0);
    for (int i = 0; i < 2 * cnt_perem; i++) {
        if (!used[i]) top_sort(i);
    }
    reverse(all(order));
}

void paint_comp() {
    int color = 0;
    comp.assign(2 * cnt_perem, -1);
    for (int i : order) {
        if (comp[i] == -1) paint(i, color++);
    }
}

void solve_2sat() { // Time: O(N + M)
    create_obr();
    find_sort();
    paint_comp();
    //If comp[a] == comp[a+cnt_perem] ==> no solution
}
