// Brute Force, DP
// 3
// 13-03-2021

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
  int n, m, q;
  cin >> n >> m >> q;
  vpii a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vi x(m);
  for (int i = 0; i < m; i++) cin >> x[i];
  sort(all(a));
  while (q--) {
    int l, r;
    cin >> l >> r;
    vi b;
    l -= 1;
    r -= 1;
    for (int i = 0; i < m; i++) {
      if (l <= i and i <= r) continue;
      b.pb(x[i]);
    }
    sort(all(b));
    vector <vi> dp(sz(a), vi(sz(b), -1));
    function <int(int,int)> rec = [&] (int x, int y) -> int {
      if (x == sz(a) or y == sz(b)) return 0;
      if (dp[x][y] != -1) return dp[x][y];
      if (a[x].first > b[y]) return dp[x][y] = rec(x, y + 1);
      int ret1 = a[x].second + rec(x + 1, y + 1);
      int ret2 = rec(x + 1, y);
      return dp[x][y] = max(ret1, ret2);
    };
    cout << rec(0, 0) << '\n';
  }
  return (0);
}
