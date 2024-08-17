#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <random>
#include <numeric>
#include <chrono>
#include <iomanip>

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
#define mp make_pair
#define fi first
#define se second
#define str(x) to_string(x)

using namespace std;
const ll inf = 1e18;
mt19937 rnd(4321);
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll l, ll r) { return (rnd() % (++r - l) + l); } //random in [l...r]
/* cout << fixed; - убрать экспоненциальный вывод.
 cout << setprecision(10); - вывод с заданной точностью.
 work with #include <iomanip> */

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    return 0;
}
