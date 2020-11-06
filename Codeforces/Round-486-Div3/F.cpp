// DP
// 4
// 05-11-2020

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
  int a, n, m;
  cin >> a >> n >> m;
  vi color(a + 1, 0);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j <= r; j++) {
      color[j] = i + 1;
    }
  }
  const int INF = 1e9;
  vi p(a + 1, INF);
  for (int i = 0; i < m; i++) {
    int xi, pi;
    cin >> xi >> pi;
    p[xi] = min(p[xi], pi);
  }
  vector <vi> dp(a + 2, vi(a + 2, -1));
  function <int(int,int)> rec = [&] (int x, int u) -> int {
    if (x == a) return 0;
    if (dp[x][u] != -1) return dp[x][u];
    int ret = INF;
    if (color[x] == color[x + 1] and color[x]) {
      if (u != a + 1) ret = min(ret, p[u] + rec(x + 1, u));
      ret = min(ret, p[x] + rec(x + 1, x));
    } else {
      ret = min(ret, p[u] + rec(x + 1, u));
      ret = min(ret, p[x] + rec(x + 1, x));
      ret = min(ret, rec(x + 1, a + 1));
    }
    return dp[x][u] = ret;
  };
  int res = rec(0, a + 1);
  if (res == INF) res = -1;
  cout << res << '\n';
  return (0);
}
