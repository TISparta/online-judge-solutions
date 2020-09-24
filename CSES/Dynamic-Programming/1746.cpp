// DP
// 2
// 13-09-2020

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
  vi x(n);
  for (int& xi: x) cin >> xi;
  vector <vi> dp(n, vi(m + 1, -1));
  const int mod = 1e9 + 7;
  function <int(int,int)> rec = [&] (int pos, int last) -> int {
    if (pos == n) return 1;
    if (dp[pos][last] != -1) return dp[pos][last];
    int ret = 0;
    for (int nxt: {last - 1, last, last + 1}) {
      if (not (1 <= nxt and nxt <= m)) continue;
      if (x[pos] != 0 and nxt != x[pos]) continue;
      ret += rec(pos + 1, nxt);
      if (ret >= mod) ret -= mod;
    };
    return dp[pos][last] = ret;
  };
  int ret = 0;
  if (x[0] != 0) {
    ret = rec(1, x[0]);
  } else {
    for (int i = 1; i <= m; i++) {
      ret += rec(1, i);
      if (ret >= mod) ret -= mod;
    }
  }
  cout << ret << '\n';
  return (0);
}
