// Greedy, Two Pointers
// 5
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
    vector <vector <pair <int, pii>>> g(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v, w, c;
      cin >> u >> v >> w >> c;
      g[u].pb(mp(v, pii(w, c)));
      g[v].pb(mp(u, pii(w, c)));
    }
    vi cnt(n + 1, 0);
    priority_queue <pair <ll, pii>> Q1;
    priority_queue <pair <ll, pii>> Q2;
    ll sum1 = 0;
    ll sum2 = 0;
    function <void(int,int)> dfs = [&] (int u, int p) -> void {
      bool is_leaf = true;
      for (auto pp: g[u]) {
        int v = pp.first;
        ll w = pp.second.first;
        int c = pp.second.second;
        if (v == p) continue;
        is_leaf = false;
        dfs(v, u);
        cnt[u] += cnt[v];
        if (c == 1) {
          sum1 += w * cnt[v];
          Q1.push(mp((w  - (w / 2)) * cnt[v], pii(w, cnt[v])));
        } else {
          sum2 += w * cnt[v];
          Q2.push(mp((w  - (w / 2)) * cnt[v], pii(w, cnt[v])));
        }
      }
      if (is_leaf) cnt[u] = 1;
    };
    dfs(1, -1);
    auto get = [&] (priority_queue <pair <ll, pii>>& Q, ll sum) {
      vll ret;
      ret.pb(sum);
      while (sum > 0) {
        auto pp = Q.top();
        Q.pop();
        ll w = pp.second.first;
        ll c = pp.second.second;
        sum -= w * c;
        w /= 2;
        sum += w * c;
        ret.pb(sum);
        Q.push(mp((w - (w / 2)) * c, pii(w, c)));
      }
      return ret;
    };
    vll x = get(Q1, sum1);
    vll y = get(Q2, sum2);
    int ans = INT_MAX;
    int j = sz(y) - 1;
    for (int i = 0; i < sz(x); i++) {
      while (j > 0 and x[i] + y[j - 1] <= S) j--;
      if (x[i] + y[j] <= S) {
        ans = min(ans, i + 2 * j);
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
