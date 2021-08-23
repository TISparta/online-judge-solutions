// Tags: DP On Trees
// Difficulty: 7.3
// Priority: 3
// Date: 22-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

template <typename T = int>
struct BIT {
  vector <T> ft;
  BIT (int n): ft(n + 2, 0) {}
  void update (int pos, T val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  }
  void update (int l, int r, T val) {
    if (l > r) return;
    update(l, val);
    update(r + 1, -val);
  }
  T sum (int pos) {
    T ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos & -pos;
    }
    return ret;
  }
  T sum (int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll n, time;
  cin >> n >> time;
  vll x(n + 1);
  for (int i = 1; i <= n; i++) cin >> x[i];
  vll t(n + 1);
  for (int i = 1; i <= n; i++) cin >> t[i];
  vll l(n + 1);
  vi who(n + 1);
  iota(all(who), 0);
  sort(all(who), [&] (int i, int j) { return t[i] < t[j]; });
  vi order(n + 1);
  for (int i = 1; i <= n; i++) order[who[i]] = i;
  vector <vi> g(n + 1);
  for (int v = 2; v <= n; v++) {
    int u;
    cin >> u >> l[v];
    g[u].pb(v);
  }
  ll travel_time = 0;
  BIT <ll> ft1(n + 2);
  BIT <ll> ft2(n + 2);
  set <int> used;
  auto compute = [&] (ll have) {
    int lo = 0, hi = n;
    while (lo != hi) {
      int mid = (lo + hi + 1) >> 1;
      if (ft1.sum(mid) <= have) lo = mid;
      else hi = mid - 1;
    }
    ll ret = ft2.sum(lo);
    have -= ft1.sum(lo);
    if (ret != 0) {
      lo = *(--used.upper_bound(lo));
      if (*(--end(used)) == lo) return ret;
    } else {
      lo = *begin(used) - 1;
    }
    int v = who[*used.upper_bound(lo)];
    ll can = have / t[v];
    assert(can <= x[v]);
    ret += can;
    return ret;
  };
  vll dp(n + 1);
  function <void(int)> dfs = [&] (int u) {
    travel_time += l[u];
    ft1.update(order[u], x[u] * t[u]);
    ft2.update(order[u], x[u]);
    used.emplace(order[u]);
    ll have = time - 2 * travel_time;
    if (have > 0) dp[u] = compute(have);
    ll mx = -1;
    ll smx = -1;
    for (int v: g[u]) {
      dfs(v);
      if (dp[v] >= mx) {
        smx = mx;
        mx = dp[v];
      } else if (dp[v] > smx) {
        smx = dp[v];
      }
    }
    if (u == 1) dp[u] = max(dp[u], mx);
    else if (sz(g[u]) > 1) dp[u] = max(dp[u], smx);
    travel_time -= l[u];
    ft1.update(order[u], -x[u] * t[u]);
    ft2.update(order[u], -x[u]);
    used.erase(order[u]);
  };
  dfs(1);
  cout << dp[1] << '\n';
  return (0);
}
