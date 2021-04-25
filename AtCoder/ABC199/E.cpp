// DP, Bitmaks
// 5.0
// 24-04-2021

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
  int n, m;
  cin >> n >> m;
  vector <vpii> query(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    query[x].emplace_back((1 << y) - 1, z);
  }
  vector <vll> dp(n + 1, vll((1 << n) + 1, -1));
  function <ll(int,int)> rec = [&] (int pos, int mask) -> ll {
    if (dp[pos][mask] != -1) return dp[pos][mask];
    for (auto [y_mask, z]: query[pos]) {
      if (__builtin_popcount(mask & y_mask) > z) return dp[pos][mask] = 0;
    }
    if (pos == n) return 1;
    ll ret = 0;
    for (int bit = 0; bit < n; bit++) {
      if (((mask >> bit) & 1) == 0) {
        ret += rec(pos + 1, mask | (1 << bit));
      }
    }
    return dp[pos][mask] = ret;
  };
  cout << rec(0, 0) << '\n';
  return (0);
}
