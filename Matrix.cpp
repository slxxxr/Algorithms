typedef vector<vector<int>> matrix;
int n, m;
matrix& matmul(matrix& a, matrix& b) {
    matrix c(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int t = 0; t < k; t++)
                c[i][j] += a[i][t] * b[t][j];
    return c;
}
matrix& binpow(matrix& a, int p) {
    matrix b(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
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
