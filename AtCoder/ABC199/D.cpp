// Bitmasks, Brute Force
// 4.0
// 24-04-2021

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
  vector <vi> g(n);
  vpii edge(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    g[a].pb(b);
    g[b].pb(a);
    edge[i] = pii(a, b);
  }
  vi color(n, 0);
  ll ans = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    fill(all(color), 0);
    // color 1
    for (int bit = 0; bit < n; bit++) if ((mask >> bit) & 1) color[bit] = 1;
    ll ways = 1;
    for (auto [u, v]: edge) {
      if (color[u] == 1 and color[v] == 1) {
        ways = 0;
      }
    }
    if (ways == 0) continue;
    for (int s = 0; s < n; s++) {
      if (color[s] != 0) continue;
      queue <int> q;
      q.push(s);
      color[s] = 2;
      int z = 1;
      int cc = 0;
      while (not q.empty() and z) {
        int u = q.front();
        cc += 1;
        q.pop();
        for (int v: g[u]) {
          if (color[v] == 1) continue;
          if (color[v] == 0) {
            color[v] = (color[u] == 2) ? 3 : 2;
            q.push(v);
          } else if (color[u] == color[v]) {
            z = 0;
          }
        }
      }
      ways *= z * 2;
    }
    ans += ways;
  }
  cout << ans << '\n';
  return (0);
}
