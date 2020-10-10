// DFS
// 2
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
  int n;
  cin >> n;
  vector <vi> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].pb(i);
    g[i].pb(p);
  }
  vi ss(n + 1, 0);
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    for (int v: g[u]) {
      if (v == p) continue;
      dfs(v, u);
      ss[u] += 1 + ss[v];
    }
  };
  dfs(1, -1);
  for (int u = 1; u <= n; u++) cout << ss[u] << " \n"[u == n];
  return (0);
}
