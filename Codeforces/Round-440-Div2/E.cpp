// Math, DFS
// 6
// 17-06-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
 
int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vpii p(n);
  vi x;
  vi y;
  for (auto& pp: p) {
    cin >> pp.first;
    cin >> pp.second;
    x.pb(pp.first);
    y.pb(pp.second);
  }
  sort(all(x));
  sort(all(y));
  vector <vpii> v(n);
  vector <vpii> h(n);
  for (int i = 0; i < n; i++) {
    p[i].first = lower_bound(all(x), p[i].first) - begin(x);
    p[i].second = lower_bound(all(y), p[i].second) - begin(y);
    v[p[i].first].pb(pii(p[i].second, i));
    h[p[i].second].pb(pii(p[i].first, i));
  }
  vector <vi> g(n);
  for (int i = 0; i < n; i++) {
    sort(all(v[i]));
    for (int j = 1; j < sz(v[i]); j++) {
      int uu = v[i][j - 1].second;
      int vv = v[i][j].second;
      g[uu].pb(vv);
      g[vv].pb(uu);
    }
    sort(all(h[i]));
    for (int j = 1; j < sz(h[i]); j++) {
      int uu = h[i][j - 1].second;
      int vv = h[i][j].second;
      g[uu].pb(vv);
      g[vv].pb(uu);
    }
  }
  vector <bool> vis(n, false);
  int V = 0;
  int SD = 0;
  set <int> ux;
  set <int> uy;
  function <void(int)> dfs = [&] (int u) -> void {
    vis[u] = true;
    V++;
    ux.insert(p[u].first);
    uy.insert(p[u].second);
    SD += sz(g[u]);
    for (int v: g[u]) {
      if (vis[v]) continue;
      dfs(v);
    }
  };
  const int mod = 1e9 + 7;
  auto modpow = [&] (ll a, ll b) {
    ll ret = 1;
    while (b) {
      if (b & 1) ret = (ret * a) % mod;
      b >>= 1;
      a = (a * a) % mod;
    }
    return ret;
  };
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    V = SD = 0;
    ux.clear();
    uy.clear();
    dfs(i);
    ll x = modpow(2, sz(ux) + sz(uy));
    // is a tree?
    if (SD == 2 * (V - 1)) x--;
    if (x < 0) x += mod;
    ans = (ans * x) % mod;
  }
  cout << ans << '\n';
  return (0);
}
