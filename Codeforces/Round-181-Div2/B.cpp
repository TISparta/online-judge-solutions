// DFS
// 3
// 03-08-2020

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
  int n, m;
  cin >> n >> m;
  vector <vi> g(n + 1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  set <int> alone;
  for (int i = 1; i <= n; i++) {
    if (g[i].empty()) {
      alone.insert(i);
    }
  }
  vector <bool> vis(n + 1, false);
  set <int> cur;
  function <void(int)> dfs = [&] (int u) -> void {
    vis[u] = true;
    cur.insert(u);
    for (int v: g[u]) if (not vis[v]) dfs(v);
  };
  vector <pair <int, pii>> ans;
  for (int i = 1; i <= n; i++) {
    if (vis[i] or g[i].empty()) continue;
    cur.clear();
    dfs(i);
    if (sz(cur) > 3) {
      cout << -1 << '\n';
      return (0);
    }
    while (sz(cur) < 3 and not alone.empty()) {
      cur.insert(*begin(alone));
      alone.erase(begin(alone));
    }
    if (sz(cur) != 3) {
      cout << -1 << '\n';
      return (0);
    }
    vi e(all(cur));
    ans.pb(mp(e[0], pii(e[1], e[2])));
  }
  if (sz(alone) % 3) {
    cout << -1 << '\n';
    return (0);
  }
  vi e(all(alone));
  for (int i = 0; i < sz(e); i += 3) {
    ans.pb(mp(e[i + 0], pii(e[i + 1], e[i + 2])));
  }
  for (auto pp: ans) {
    cout << pp.first << ' ' << pp.second.first << ' ' << pp.second.second << '\n';
  }
  return (0);
}
