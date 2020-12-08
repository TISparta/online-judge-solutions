// DFS, Greedy
// 5
// 05-12-2020

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector <vi> g(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    int ans = 0;
    function <int(int,int)> dfs = [&] (int u, int p) -> int {
      vi x;
      for (int v: g[u]) {
        if (v == p) continue;
        x.pb(1 + dfs(v, u));
      }
      sort(rall(x));
      if (u == 1) {
        ans = max(ans, x.front());
        if (sz(x) >= 2) ans = max(ans, x[1] + 1);
      }
      if (u != 1 and sz(x) >= 1) ans = max(ans, x.front() + 1);
      if (x.empty()) return 0;
      return x.back();
    };
    dfs(1, -1);
    cout << ans << '\n';
  }
  return (0);
}
