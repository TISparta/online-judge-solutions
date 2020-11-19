// Constructive Algorithms, BFS
// 5
// 13-11-2020

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
  for (int i = 1; i <= n; i++) {
    if (sz(g[i]) > 4) {
      cout << "NO\n";
      return (0);
    }
  }
  cout << "YES\n";
  vpll ans(n + 1);
  const vi dr = {0, -1, 0, 1};
  const vi dc = {1, 0, -1, 0};
  int k = 40;
  vector <vi> order = {
    {0, 1, 3, 2},
    {1, 0, 2, 3},
    {2, 1, 3, 0},
    {3, 0, 2, 1}
  };
  int leaf = -1;
  for (int u = 1; u <= n; u++) {
    if (sz(g[u]) <= 1) leaf = u;
  }
  assert(leaf != -1);
  queue <int> q;
  q.emplace(leaf);
  const int INF = 1e9;
  vi dis(n + 1, INF);
  vi dir(n + 1);
  dis[leaf] = 0;
  dir[leaf] = 0;
  ans[leaf] = mp(0, 0);
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    vi nxt = order[dir[u]];
    int k = 40 - dis[u];
    int cur = 0;
    for (int v: g[u]) {
      if (dis[v] > dis[u] + 1) {
        dis[v] = dis[u] + 1;
        auto [r, c] = ans[u];
        r += (1LL << k) * dr[nxt[cur]];
        c += (1LL << k) * dc[nxt[cur]];
        ans[v] = mp(r, c);
        dir[v] = nxt[cur];
        cur += 1;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
  return (0);
}
