// Binary Lifting 
// 3
// 08-10-2020

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
  int n, q;
  cin >> n >> q;
  vector <vi> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].pb(i);
    g[i].pb(p);
  }
  const int LG = 18;
  vector <vi> up(n + 1, vi(LG, -1));
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    for (int bit = 1; bit < LG; bit++) {
      int v = up[u][bit - 1];
      // 2^bit = 2^(bit - 1) -> 2^(bit - 1)
      if (v == -1) break;
      up[u][bit] = up[v][bit - 1];
    }
    for (int v: g[u]) {
      if (v == p) continue;
      up[v][0] = u;
      dfs(v, u);
    }
  };
  dfs(1, -1);
  auto walk = [&] (int u, int k) {
    for (int bit = 0; bit < LG and u != -1; bit++) {
      if ((k >> bit) & 1) {
        u = up[u][bit];
      }
    }
    return u;
  };
  while (q--) {
    int u, k;
    cin >> u >> k;
    cout << walk(u, k) << '\n';
  }
  return (0);
}
