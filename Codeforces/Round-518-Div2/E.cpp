// BFS, DFS
// 3
// 05-04-2021

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
  int n, k;
  cin >> n >> k;
  vector <vi> g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vi dis(n + 1, 0);
  vi par(n + 1);
  dis[0] = -1;
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    dis[u] = dis[p] + 1;
    par[u] = p;
    for (int v: g[u]) if (v != p) dfs(v, u);
  };
  dfs(1, 0);
  int leaf = max_element(all(dis)) - begin(dis);
  dfs(leaf, 0);
  int dia = *max_element(all(dis));
  leaf = max_element(all(dis)) - begin(dis);
  if (dia & 1) {
    cout << "No\n";
    return (0);
  }
  int c = leaf;
  for (int i = 0; i < dia / 2; i++) c = par[c];
  bool ok = (dia == 2 * k);
  const int INF = 1e9;
  fill(all(dis), INF);
  queue <int> q;
  dis[c] = 0;
  q.push(c);
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    for (int v: g[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  for (int u = 1; u <= n; u++) {
    if (sz(g[u]) == 1) {
      ok &= (dis[u] == k);
    } else {
      if (u == c) ok &= (sz(g[u]) >= 3);
      else ok &= (sz(g[u]) >= 4);
    }
  }
  if (ok) cout << "Yes\n";
  else cout << "No\n";
  return (0);
}
