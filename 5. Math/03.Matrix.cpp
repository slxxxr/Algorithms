typedef vector<vector<ll>> matrix;
const ll mod = 1e9 + 7;

matrix matmul(matrix &a, matrix &b) { // A[n][k] * B[k][m]; Time: O(N * M * K)
    int n = a.size(), k = a[0].size(), m = b[0].size();
    matrix c(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int t = 0; t < k; t++)
                c[i][j] = (c[i][j] + a[i][t] * b[t][j] % mod) % mod;
    return c;
}

matrix binpow(matrix &a, ll p) {// Time: O(N ^ 3 * logP)
    int n = a.size();
    matrix b(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
        b[i][i] = 1;

    while (p > 0) {
        if (p & 1)
            b = matmul(b, a);
        a = matmul(a, a);
        p >>= 1;
    }
    return b;
}

vector<double> gauss(matrix a) {
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        int best = i;
        for (int j = i + 1; j < n; j++)
            if (abs(a[j][i]) > abs(a[best][i]))
                best = j;
        swap(a[best], a[i]);
        for (int j = n; j >= i; j--)
            a[i][j] /= a[i][i];
        for (int j = 0; j < n; j++)
            if (j != i)
                for (int k = n; k >= i; k--)
                    a[j][k] -= a[i][k] * a[j][i];
    }
    vector<double> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = a[i][n];
    return ans;
}
