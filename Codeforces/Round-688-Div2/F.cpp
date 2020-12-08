// DP, BIT
// 5
// 04-12-2020

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

template <typename T = int>
struct BIT {
  vector <T> ft;
  BIT (int n): ft(n + 2, 0) {}
  void update (int pos, T val) {
    while (pos < sz(ft)) {
      ft[pos] += val;
      pos += pos & -pos;
    }
  }
  void update (int l, int r, T val) {
    if (l > r) return;
    update(l, val);
    update(r + 1, -val);
  }
  T sum (int pos) {
    T ret = 0;
    while (pos) {
      ret += ft[pos];
      pos -= pos & -pos;
    }
    return ret;
  }
  T sum (int l, int r) {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    BIT ft(n + 2);
    const int INF = 1e9;
    vector <vi> dp(n + 1, vi(n + 2, INF));
    fill(all(dp[n]), 0);
    for (int i = n - 1; i >= 1; i--) {
      fill(all(ft.ft), 0);
      for (int j = i + 1; j <= a[i] + i; j++) {
        int cost = ft.sum(j, n);
        dp[i][j] = min(dp[i][j], cost + dp[j][a[i] + i + 1]);
        ft.update(j + a[j], 1);
      }
      for (int j = n - 1; j >= 1; j--) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
    }
    cout << dp[1][1] << '\n';
  }
  return (0);
}
