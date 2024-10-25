// d - matrix adj. d[i][i] = 0
vector<vll> d(n, vll(n, inf));
for (int k = 0; k < n; ++k) {// Time: O(N^3)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < inf && d[k][j] < inf)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
 
