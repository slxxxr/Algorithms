Нахождение кратчайшего расстояния между всеми парами вершин за N^3
d-матрица смежности. d[i][i]=0

  vector<vll> d(n, vll(n, inf));
for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
 
