// DP
// 5
// 07-08-2020

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
    int n;
    cin >> n;
    vpii arr(n);
    vi val;
    for (auto&pp: arr) {
      cin >> pp.first >> pp.second;
      val.pb(pp.first);
      val.pb(pp.second);
    }
    sort(all(val));
    val.erase(unique(all(val)), end(val));
    int m = sz(val);
    vector <vi> g(m + 1);
    for (auto&pp: arr) {
      pp.first = lower_bound(all(val), pp.first) - begin(val);
      pp.second = lower_bound(all(val), pp.second) - begin(val);
      g[pp.first].pb(pp.second);
    }
    for (auto& row: g) {
      sort(all(row));
    }
    vector <vi> dp(m + 1, vi(m + 1, -1));
    function <int(int,int)> rec = [&] (int l, int r) -> int {
      if (l > r) return 0;
      if (dp[l][r] != -1) return dp[l][r];
      int whole = binary_search(all(g[l]), r);
      int ret = whole + rec(l + 1, r);
      for (int p: g[l]) {
        if (p >= r) break;
        ret = max(ret, whole + rec(l, p) + rec(p + 1, r));
      }
      return dp[l][r] = ret;
    };
    cout << rec(0, m) << '\n';
  }
  return (0);
}
