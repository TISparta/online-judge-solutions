// SCC
// 5
// 11-09-2020

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
  vector <vi> g(n);
  vector <vi> rg(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int ai;
      cin >> ai;
      if (ai > 0) g[i].pb(j), rg[j].pb(i);
    }
  }
  vector <bool> vis(n, false);
  vi topo;
  function <void(int)> dfs1 = [&] (int u) -> void {
    vis[u] = true;
    for (int v: g[u]) if (not vis[v]) dfs1(v);
    topo.pb(u);
  };
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    cc += 1;
    dfs1(i);
  }
  if (cc > 1) {
    cout << "NO\n";
    return (0);
  }
  int scc = 0;
  reverse(all(topo));
  fill(all(vis), false);
  function <void(int)> dfs2 = [&] (int u) -> void {
    vis[u] = true;
    for (int v: rg[u]) if (not vis[v]) dfs2(v);
  };
  for (int u: topo) {
    if (vis[u]) continue;
    scc += 1;
    dfs2(u);
  }
  if (scc == 1) cout << "YES\n";
  else cout << "NO\n";
  return (0);
}
