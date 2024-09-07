class Query_on_Tree {
private:

    struct node {
        int mn; // max
    };

    const node zero = { inf };

    void comb(node& a, node& b) {// set a = comb(a, b). 
        a.mn = min(a.mn, b.mn);
    }

    int n, logn, root;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<node>> up_info;

    void calc_depth(int v, vector<vector<pair<int, int>>>& gr, int p = -1) {
        for (auto [u, c] : gr[v]) {
            if (u != p) {
                depth[u] = depth[v] + 1;
                up[u][0] = v;
                up_info[u][0] = { c };
                
                calc_depth(u, gr, v);
            }
        }
    }

    void binary_lifting() {
        for (int i = 1; i < logn; i++) { // up[i][0] = parent[i]
            for (int v = 0; v < n; v++) {
                
                up[v][i] = (up[v][i - 1] == -1 ? -1 : up[up[v][i - 1]][i - 1]);
                
                if (up[v][i] != -1) {
                    comb(up_info[v][i], up_info[v][i - 1]);
                    comb(up_info[v][i], up_info[up[v][i - 1]][i - 1]);
                }
            }
        }
    }

public:
    Query_On_Tree(vector<vector<pair<int, int>>>& gr, int _root = 0) { // time: O(N*logN), memory: O(N*logN)
        n = gr.size();
        logn = (int)log2(n) + 1;
        root = _root;

        depth.assign(n, 0);
        up.assign(n, vector<int>(logn, -1));
        up_info.assign(n, vector<node>(logn, zero));

        calc_depth(root, gr, -1);
        binary_lifting();
    }

    int get_min(int v, int u) {// return min edge between V and U (0 - index). time: O(logN).  
        assert(v != u);

        node res = zero;

        if (depth[v] > depth[u]) { swap(v, u); }

        int delta = depth[u] - depth[v];
        for (int i = 0, pw = 1; i < logn; i++, pw <<= 1) {
            if ((pw & delta)) {
                comb(res, up_info[u][i]);
                u = up[u][i];
            }
        }

        for (int i = logn - 1; i >= 0; i--) {
            if (up[v][i] != up[u][i]) {
                comb(res, up_info[v][i]);
                comb(res, up_info[u][i]);
                v = up[v][i];
                u = up[u][i];
            }
        }

        if (v != u) {
            comb(res, up_info[v][0]);
            comb(res, up_info[u][0]);
        }

        return res.mn;
    }
};
