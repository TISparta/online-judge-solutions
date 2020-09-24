// Greedy
// 4
// 09-08-2020

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
  int tc;
  cin >> tc;
  while (tc--) {
    ll n, S;
    cin >> n >> S;
    vector <vpii> g(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].pb(pii(v, w));
      g[v].pb(pii(u, w));
    }
    vi cnt(n + 1, 0);
    priority_queue <pair <ll, pii>> Q;
    ll sum = 0;
    function <void(int,int)> dfs = [&] (int u, int p) -> void {
      bool is_leaf = true;
      for (auto pp: g[u]) {
        int v = pp.first;
        ll w = pp.second;
        if (v == p) continue;
        is_leaf = false;
        dfs(v, u);
        cnt[u] += cnt[v];
        Q.push(mp((w  - (w / 2)) * cnt[v], pii(w, cnt[v])));
        sum += w * cnt[v];
      }
      if (is_leaf) cnt[u] = 1;
    };
    dfs(1, -1);
    int ans = 0;
    while (sum > S) {
      auto pp = Q.top();
      Q.pop();
      ll w = pp.second.first;
      ll c = pp.second.second;
      sum -= w * c;
      w /= 2;
      sum += w * c;
      Q.push(mp((w - (w / 2)) * c, pii(w, c)));
      ans += 1;
    }
    cout << ans << '\n';
  }
  return (0);
}
