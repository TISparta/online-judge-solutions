// Tags: Constructive Algorithms
// Difficulty: 5.3
// Priority: 3
// Date: 17-11-2021

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
  int n, m;
  cin >> n >> m;
  vector <int> root(n + 1);
  vector <int> cc(n + 1);
  vector <int> mn(n + 1);
  vector <int> mx(n + 1);
  for (int i = 1; i <= n; i++) cc[i] = 1, mn[i] = mx[i] = i, root[i] = i;
  function <int(int)> get = [&] (int u) -> int { return root[u] = (root[u] == u) ? u : get(root[u]); };
  function <int(int,int)> join = [&] (int u, int v) -> int {
    int x = get(u);
    int y = get(v);
    if (x == y) return 0;
    if (x < y) swap(x, y);
    root[y] = x;
    cc[x] += cc[y];
    mn[x] = min(mn[x], mn[y]);
    mx[x] = max(mx[x], mx[y]);
    return 1;
  };
  for (int i = 0; i < m; i++) {
    int u, v; 
    cin >> u >> v;
    join(u, v);
  }
  int ans = 0;
  int k_last = n;
  for (int i = n; i >= 1; i--) {
    int r = get(i);
    int from = mn[r];
    int to = mx[r];
    if (cc[r] == mx[r] - mn[r] + 1) continue;
    to = min(k_last, to);
    for (int k = from; k <= to; k++) {
      ans += join(i, k);
    }
    k_last = min(k_last, from);
  }
  cout << ans << '\n';
  return (0);
}
