struct fib { long long fib1, fib2; }; /* используем структуру, чтобы хранить вектор - строку
                                      fib1 - число из 1-ой строки, 1-ого столбца
                                      fib2 - число из 1-ой строки, 2-ого столбца
                                      */
struct A { long long a1, a2, a3, a4; };// также используем структуру, чтобы хранить матрицу A
fib st = { 0,1 }; A st1 = { 0,1,1,1 }; // создадим начальные вектор-строку и матрицу A
const long long md = (1e9 + 7);// нужно не забывать смотреть числа по модулю, поэтому создадим отдельную функцию для этого
long long mod(long long a) { return a % md; }
A comp(A a, A b) { // функция произведения двух матриц размерами 2x2, необходимо для вычисления A в степени N
    long long b1 = mod(a.a1 * b.a1 + a.a2 * b.a3);
    long long b2 = mod(a.a1 * b.a2 + a.a2 * b.a4);
    long long b3 = mod(a.a3 * b.a1 + a.a4 * b.a3);
    long long b4 = mod(a.a3 * b.a2 + a.a4 * b.a4);
    return { b1, b2, b3, b4 };
}
fib comp1(A a, fib b) { // функция произведения вектор строки 1x2 и матрицы 2x2, пригодится для итогового ответа
    long long b1 = mod(b.fib1 * a.a1 + b.fib2 * a.a3);
    long long b2 = mod(b.fib1 * a.a2 + b.fib2 * a.a4);
    return { b1, b2 };
}
A step(A a, long long n) { // функция для возведения A в степень n
    if (n == 0) return { 1, 0, 0, 1 };
    if (n == 1) return { 0, 1, 1, 1 };
    A f = step(a, n / 2);
    return comp(f, comp(f, step(a, n % 2)));
}
pll Fn(ll n) { //Вызывается, указывая степень 
    st1 = step(st1, n);
    st = comp1(st1, st);
    /*st.fib1=F_n; st.fib2=F_n+1
    F_1=1, F_2=1, F_3=2, F_4=3 ....*/
    return { st.fib1,st.fib2 };
}
