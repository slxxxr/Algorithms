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

typedef long double db;
typedef long long ll;

#define write(x) for(auto &i: x) cout << i << " "
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

ll n, cnt1, cnt2, cnt_edge = 0;
vector<vll> gr;
vll used, color;
vpll cnt, rebr;



void dfs(ll v) {
    used[v] = 1;
    if (color[v] == 1) cnt[v].first++;
    if (color[v] == 2) cnt[v].second++;
    for (ll u : gr[v]) {
        if (!used[u]) {
            rebr[cnt_edge++] = { v,u };
            dfs(u);
            cnt[v].first += cnt[u].first;
            cnt[v].second += cnt[u].second;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    gr.resize(n);
    color.resize(n);
    used.assign(n, false);
    cnt.assign(n, { 0,0 });
    rebr.resize(n - 1);

    forn(i, n) {
        cin >> color[i];
        if (color[i] == 1) cnt1++;
        if (color[i] == 2) cnt2++;
    }

    forn(i, n - 1) {
        ll v, u; 
        cin >> v >> u;
        gr[--v].pb(--u);
        gr[u].pb(v);
    }

    dfs(0);

    ll ans = 0;
    for (auto& pr : rebr) {
        if ((cnt[pr.second].first == cnt1 and cnt[pr.second].second == 0) 
            or (cnt[pr.second].second == cnt2 and cnt[pr.second].first == 0)) ans++;
    }

    cout << ans;
  
    return 0;
}