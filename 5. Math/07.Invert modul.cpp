int inv(int a, int m) {
    if (a <= 1)
        return 1;
    return (1 - 1ll * inv(m % a, a) * m) / a + m;
}
