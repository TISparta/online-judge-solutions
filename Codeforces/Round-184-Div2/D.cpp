// Tags: Combinatorics
// Difficulty: 6.0
// Priority: 1
// Date: 22-05-2021

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
  int n, m, k;
  cin >> n >> m >> k;
  int l = -1, r = -1;
  int one = 0;
  int die = 0;
  vi can(n + 1, 1);
  int mx = -1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u + 1 == v) one += 1;
    else if (v - u != k + 1) die = 1;
    if (v - u == k + 1) {
      if (l == -1) {
        l = u, r = v;
      } else {
        if (r <= u) die = 1;
        else can[u] = 0, mx = max(mx, u);
      }
    }
  }
  if (die) {
    cout << 0 << '\n';
    return (0);
  }
  ll ans = 1;
  const ll mod = 1e9 + 7;
  vll p2(n + 1);
  p2[0] = 1;
  for (int i = 1; i <= n; i++) p2[i] = (2LL * p2[i - 1]) % mod;
  if (l != -1) {
    ans = 0;
    ll ways = 1;
    vi acc_in(n + 1, 0);
    vi acc_out(n + 1, 0);
    for (int u = l + 1; u < r; u++) {
      if (not can[u]) continue;
      ll add = 1;
      if (1 <= u - k - 1 and mx < u) acc_in[u] = 1;
      if (u + k + 1 <= n) acc_out[u] = 1;
    }
    for (int i = l; i <= r; i++) acc_out[i] += acc_out[i - 1];
    for (int i = r - 1; i >= l; i--) acc_in[i] += acc_in[i + 1];
    for (int u = l + 1; u < r; u++) {
      if (not can[u]) continue;
      if (u + k + 1 <= n) {
        ll add = p2[acc_out[u - 1]] * p2[acc_in[u + 1]];
        add %= mod;
        ans += add;
        if (ans >= mod) ans -= mod;
      }
    }
    if (acc_in[l]) ans += p2[acc_in[l]];
    else ans += 1;
    if (ans >= mod) ans -= mod;
  } else {
    for (int r = 1 + k + 1; r <= n; r++) {
      int l = r - k - 1;
      // l < x < r and 1 <= x - k - 1
      // l < x < r and 0 < x - k - 1
      // l < x < r and k + 1 < x
      l = max(l, k + 1);
      ll add = max(0, r - l - 1);
      ans += p2[add];
      if (ans >= mod) ans -= mod;
    }
  }
  cout << ans << '\n';
  return (0);
}
