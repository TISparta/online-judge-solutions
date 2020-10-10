// DP
// 4
// 09-10-2020

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
  vector <vi> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector <vpii> dp1(n + 1);
  function <void(int,int)> dfs1 = [&] (int u, int p) -> void {
    dp1[u].pb(pii(0, -1));
    for (int v: g[u]) {
      if (v == p) continue;
      dfs1(v, u);
      dp1[u].pb(pii(1 + dp1[v][0].first, v));
    }
    sort(rall(dp1[u]));
    dp1[u].erase(unique(all(dp1[u])), end(dp1[u]));
  };
  dfs1(1, -1);
  vector <vpii> dp2(n + 1);
  function <void(int,int)> dfs2 = [&] (int u, int p) -> void {
    if (p == -1) {
      dp2[u] = dp1[u];
    } else {
      for (auto pp: dp1[u]) {
        dp2[u].pb(pp);
        if (sz(dp2[u]) == 2) break;
      }
      int cnt = 0;
      for (auto [w, c]: dp2[p]) {
        if (cnt == 2) break;
        if (c == u) continue;
        cnt += 1;
        dp2[u].pb(pii(1 + w, p));
      }
      sort(rall(dp2[u]));
      dp2[u].erase(unique(all(dp2[u])), end(dp2[u]));
    }
    for (int v: g[u]) {
      if (v == p) continue;
      dfs2(v, u);
    }
  };
  dfs2(1, -1);
  for (int i = 1; i <= n; i++) cout << dp2[i][0].first << " \n"[i == n];
  return (0);
}
