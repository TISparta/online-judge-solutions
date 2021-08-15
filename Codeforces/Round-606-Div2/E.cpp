// Tags: DFS
// Difficulty: 6.0
// Priority: 1
// Date: 14-04-2021

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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector <vi> g(n + 1);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    vi vis(n + 1, 0);
    function <void(int,int)> dfs = [&] (int u, int b) -> void {
      vis[u] = 1;
      for (int v: g[u]) {
        if (not vis[v] and v != b) dfs(v, b);
      }
    };
    dfs(a, b);
    ll x = n - 1 - accumulate(all(vis), 0);
    fill(all(vis), 0);
    dfs(b, a);
    ll y = n - 1 - accumulate(all(vis), 0);
    cout << x * y << '\n';
  }
  return (0);
}
