class LCA {
private:
    int _n, _logn, _root;
    vector<int> _depth;
    vector<vector<int>> _up;

    void calc_depth(int v, vector<vector<int>>& gr, int p = -1) {
        _depth[v] = (p == -1 ? 0 : _depth[p] + 1);
        _up[v][0] = p;
        for (ll u : gr[v]) {
            if (u != p) {
                calc_depth(u, gr, v);
            }
        }
    }

    void binary_lifting() {
        for (int i = 1; i < _logn; i++) { // up[i][0] = parent[i]
            for (int v = 0; v < _n; v++) {
                _up[v][i] = (_up[v][i - 1] == -1 ? -1 : _up[_up[v][i - 1]][i - 1]);
            }
        }
    }

public:
    LCA(vector<vector<int>>& gr, int _root = 0) {// Time: O(NlogN)
        _n = gr.size();
        _logn = (int)log2(_n) + 1;
        _root = _root;

        _depth.assign(_n, 0);
        _up.assign(_n, vector<int>(_logn, -1));

        calc_depth(_root, gr, -1);
        binary_lifting();
    }


    int get_lca(int v, int u) {// Time: O(logN)
        if (_depth[v] > _depth[u]) { swap(v, u); }

        int delta = _depth[u] - _depth[v];
        for (int i = 0, pw = 1; i < _logn; i++, pw <<= 1) {
            if ((pw & delta)) {
                u = _up[u][i];
            }
        }

        for (int i = _logn - 1; i >= 0; i--) {
            if (_up[v][i] != _up[u][i]) {
                v = _up[v][i];
                u = _up[u][i];
            }
        }

        return (u == v ? u : _up[u][0]);
    }
};
