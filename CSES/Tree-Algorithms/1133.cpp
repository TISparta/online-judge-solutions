// DP, DFS
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
  vll dp1(n + 1, 0);
  vi ss(n + 1, 0);
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    ss[u] = 1;
    for (int v: g[u]) {
      if (v == p) continue;
      dfs(v, u);
      dp1[u] += ss[v] + dp1[v];
      ss[u] += ss[v];
    }
  };
  vll dp2(n + 1, 0);
  function <void(int,int)> reroot = [&] (int u, int p) -> void {
    if (p == -1) {
      dp2[u] = dp1[u];
    } else {
      ll cont = ss[u] + dp1[u];
      dp2[u] = dp1[u] + (dp2[p] - cont) + (n - ss[u]);
    }
    for (int v: g[u]) {
      if (v == p) continue;
      reroot(v, u);
    }
  };
  dfs(1, -1);
  reroot(1, -1);
  for (int u = 1; u <= n; u++) cout << dp2[u] << " \n"[u == n];
  return (0);
}
