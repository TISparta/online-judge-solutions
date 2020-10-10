// DFS
// 09-10-2020
// 3

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
  vi dis(n + 1, -1);
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    dis[u] = dis[p] + 1;
    for (int v: g[u]) if (v != p) dfs(v, u);
  };
  dfs(1, 0);
  int leaf = max_element(all(dis)) - begin(dis);
  dfs(leaf, 0);
  cout << *max_element(all(dis)) << '\n';
  return (0);
}
