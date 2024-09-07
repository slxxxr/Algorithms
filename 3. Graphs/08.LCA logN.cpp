class LCA {
private:
    int n, logn, root;
    vector<int> depth;
    vector<vector<int>> up;

    void calc_depth(int v, vector<vector<int>>& gr, int p = -1) {
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        up[v][0] = p;
        for (ll u : gr[v]) {
            if (u != p) {
                calc_depth(u, gr, v);
            }
        }
    }

    void binary_lifting() {
        for (int i = 1; i < logn; i++) { // up[i][0] = parent[i]
            for (int v = 0; v < n; v++) {
                up[v][i] = (up[v][i - 1] == -1 ? -1 : up[up[v][i - 1]][i - 1]);
            }
        }
    }

public:
    LCA(vector<vector<int>>& gr, int _root = 0) { // time: O(N*logN), memory: O(N*logN)
        n = gr.size();
        logn = (int)log2(n) + 1;
        root = _root;

        depth.assign(n, 0);
        up.assign(n, vector<int>(logn, -1));

        calc_depth(root, gr, -1);
        binary_lifting();
    }


    int get_lca(int v, int u) {// time: O(logN)
        if (depth[v] > depth[u]) { swap(v, u); }

        int delta = depth[u] - depth[v];
        for (int i = 0, pw = 1; i < logn; i++, pw <<= 1) {
            if ((pw & delta)) {
                u = up[u][i];
            }
        }

        for (int i = logn - 1; i >= 0; i--) {
            if (up[v][i] != up[u][i]) {
                v = up[v][i];
                u = up[u][i];
            }
        }

        return (u == v ? u : up[u][0]);
    }
};
