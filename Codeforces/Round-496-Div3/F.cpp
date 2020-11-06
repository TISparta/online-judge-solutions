// Dijkstra, Backtracking
// 5
// 22-10-2020

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
  vector <vpii> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(pii(v, i));
    g[v].pb(pii(u, i));
  }
  const int INF = 1e9;
  vi dis(n + 1, INF);
  dis[1] = 0;
  set <pii> q;
  q.emplace(0, 1);
  vector <vi> take(n + 1);
  while (not q.empty()) {
    auto [di, u] = *begin(q);
    q.erase(begin(q));
    for (auto [v, i]: g[u]) {
      if (dis[v] > dis[u] + 1) {
        q.erase(pii(dis[v], v));
        take[v].clear();
        take[v].pb(i);
        dis[v] = dis[u] + 1;
        q.emplace(dis[v], v);
      } else if (dis[v] == dis[u] + 1) {
        take[v].pb(i);
      }
    }
  }
  string ans(m, '0');
  int tt = 0;
  vector <string> res;
  function <void(int)> backtrack = [&] (int u) -> void {
    if (tt == k) return;
    if (u == n + 1) {
      tt += 1;
      res.pb(ans);
      return;
    }
    if (sz(take[u]) == 0) {
      backtrack(u + 1);
    }
    for (int i: take[u]) {
      ans[i] = '1';
      backtrack(u + 1);
      if (tt == k) return;
      ans[i] = '0';
    }
  };
  backtrack(1);
  cout << sz(res) << '\n';
  for (auto x: res) cout << x << '\n';
  return (0);
}
