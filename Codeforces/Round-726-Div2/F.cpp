// Tags: Constructive Algorithms
// Difficulty: 7.5
// Priority: 1
// Date: 12-07-2021

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
    int n, m;
    cin >> n >> m;
    vi x(n + 1);
    vi y(n + 1);
    int p1 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x[i];
      p1 += (x[i] & 1);
    }
    int p2 = 0;
    for (int i = 1; i <= n; i++) {
      cin >> y[i];
      p2 += (y[i] & 1);
    }
    vector <vi> g(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    p1 &= 1;
    p2 &= 1;
    if (p1 != p2) {
      cout << "NO\n";
      continue;
    }
    vi color(n + 1, -1);
    bool is_bipartite = true;
    for (int i = 1; i <= n; i++) {
      if (color[i] != -1) continue;
      queue <int> q;
      q.push(i);
      color[i] = 1;
      while (not q.empty()) {
        int u = q.front(); q.pop();
        for (int v: g[u]) {
          if (color[v] == -1) {
            color[v] = 1 - color[u];
            q.push(v);
          } else if (color[u] == color[v]) {
            is_bipartite = false;
          }
        }
      }
    }
    if (not is_bipartite) {
      cout << "YES\n";
      continue;
    }
    vll sum(2);
    for (int i = 1; i <= n; i++) {
      sum[color[i]] += x[i] - y[i];
    }
    if (sum[0] == sum[1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return (0);
}
