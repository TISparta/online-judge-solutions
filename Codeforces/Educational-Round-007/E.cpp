// Tags: DFS
// Difficulty: 6.5
// Priority: 1
// Date: 26-12-2019

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <vector <int>> T(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    T[u].pb(v);
    T[v].pb(u);
  }
  vector <int> dis(n + 1);
  vector <int> leaf;
  function <void(int,int)> dfs = [&] (int u, int p) -> void {
    dis[u] = dis[p] + 1;
    int children = 0;
    for (int v: T[u]) {
      if (v == p) continue;
      children++;
      dfs(v, u);
    }
    if (children == 0) leaf.pb(dis[u]);
  };
  dis[1] = 0;
  int ans = 0;
  for (int u: T[1]) {
    leaf.clear();
    dfs(u, 1);
    sort(all(leaf));
    for (int i = 1; i < sz(leaf); i++) {
      leaf[i] = max(leaf[i], leaf[i - 1] + 1);
    }
    ans = max(ans, leaf.back());
  }
  cout << ans << '\n';
  return (0);
}
