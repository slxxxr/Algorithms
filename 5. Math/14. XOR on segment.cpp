ll get_xor(ll n) { // return 0^1^2^...^(n-2)^(n-1)^n

	if (n % 4 == 0) { return n; }
	if (n % 4 == 1) { return 1; }
	if (n % 4 == 2) { return n + 1; }
	if (n % 4 == 3) { return 0; }
}

ll get_xor(ll l, ll r) { // return l^(l+1)^(l+2)^...^(r-2)^(r-1)^r
    return get_xor(r) - get_xor(max(0LL, l - 1));
}
