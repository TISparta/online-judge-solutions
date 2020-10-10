// DFS, DP
// 3
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
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  vector <vi> dp(n + 1, vi(2));
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    int sum = 0;
    for (int v: g[u]) {
      if (v == p) continue;
      dfs(v, u);
      sum += *max_element(all(dp[v]));
    }
    dp[u][0] = sum;
    for (int v: g[u]) {
      if (v == p) continue;
      dp[u][1] = max(dp[u][1], sum - *max_element(all(dp[v])) + 1 + dp[v][0]);
    }
  };
  dfs(1, -1);
  cout << *max_element(all(dp[1])) << '\n';
  return (0);
}
