int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

/*
Работает за sqrt(n)
a^phi(m)===1(mod m) если а и m взаимно простые => a^(phi(m)-1) - обратный элемент к a
*/
