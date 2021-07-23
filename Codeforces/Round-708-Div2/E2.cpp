// Tags: DP
// Difficulty: 6.5
// Priority: 2
// Date: 17-03-2021

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
  const int N = 1e7 + 1;
  vi f(N, 0);
  for (int u = 2; u < N; u++) {
    if (f[u] != 0) continue;
    for (int v = u; v < N; v += u) {
      f[v] = u;
    }
  }
  f[1] = 1;
  auto get = [&] (int a) {
    int rep = 1;
    while (a != 1) {
      int z = f[a];
      int e = 0;
      while (a % z == 0) {
        e += 1;
        a /= z;
      }
      if (e & 1) rep *= z;
    }
    return rep;
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    map <int, int> zz;
    vi a(n + 1);
    vi prev(n + 1, -1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] = get(a[i]);
      if (zz.count(a[i])) {
        prev[i] = zz[a[i]];
      }
      zz[a[i]] = i;
    }
    const int INF = 1e9;
    vector <vi> dp(n + 1, vi(k + 1, INF));
    vi pos;
    for (int j = 0; j <= k; j++) dp[0][j] = 0;
    for (int i = 1; i <= n; i++) {
      int cur = i;
      int it = 0;
      while (prev[cur] != -1 and it < k + 1) {
        pos.pb(prev[cur]);
        it += 1;
      }
      sort(rall(pos));
      pos.erase(unique(all(pos)), end(pos));
      while (sz(pos) > k + 1) pos.pop_back();
      while (sz(pos) < k + 1) pos.pb(0);
      for (int j = 0; j <= k; j++) {
        for (int z = j; z <= k; z++) {
          dp[i][z] = min(dp[i][z], 1 + dp[pos[j]][z - j]);
        }
      }
    }
    cout << dp[n][k] << '\n';
  }
  return (0);
}
