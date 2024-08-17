#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 
#endif


using namespace std;

typedef long double db;
typedef long long ll;

#define print(x) for(auto it = x.begin(); it != x.end(); it++) cout << *it << " \n"[it == --x.end()]
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define forn(i, n) for (ll i = 0; i < (ll)(n); i++)
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define pb push_back
#define fi first
#define se second
#define str(x) to_string(x)

const ll inf = 1e18;
mt19937 rnd(4321);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll l, ll r) { return (rnd() % (++r - l) + l); } //random in [l...r]


void solve() {
    
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 

    ll test_cnt = 1;
    cin >> test_cnt;

    while (test_cnt--) {
        solve();
    }
} 
