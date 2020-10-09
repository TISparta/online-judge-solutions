// BFS
// 5
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
  int n, m;
  cin >> n >> m;
  vector <vpii> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[v].emplace_back(u, w);
  }
  const int INF = 1e9;
  vector <vi> dis(n + 1, vi(2, INF));
  dis[n][0] = dis[n][1] = 0;
  queue <int> q;
  q.emplace(n);
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    if (max(dis[u][0], dis[u][1]) == INF) continue;
    for (auto [v, t]: g[u]) {
      int d = max(dis[u][0], dis[u][1]);
      if (d + 1 < dis[v][t]) {
        dis[v][t] = d + 1;
        q.emplace(v);
      }
    }
  }
  if (max(dis[1][0], dis[1][1]) == INF) {
    cout << -1 << '\n';
  } else {
    cout << max(dis[1][0], dis[1][1]) << '\n';
  }
  for (int i = 1; i <= n; i++) {
    cout << "10"[dis[i][0] > dis[i][1]];
  }
  cout << '\n';
  return (0);
}
