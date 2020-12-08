// Implementation
// 3
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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    const int INF = 1e9;
    vector <vi> mx_r(n, vi(10, -INF));
    vector <vi> mn_r(n, vi(10, INF));
    vi mn_row(10, INF);
    vi mx_row(10, -INF);
    vi mn_col(10, INF);
    vi mx_col(10, -INF);
    vector <vi> mx_c(n, vi(10, -INF));
    vector <vi> mn_c(n, vi(10, INF));
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        int d = s[r][c] - '0';
        mx_r[r][d] = max(mx_r[r][d], c);
        mn_r[r][d] = min(mn_r[r][d], c);
        mn_row[d] = min(mn_row[d], r);
        mx_row[d] = max(mx_row[d], r);
        mn_col[d] = min(mn_col[d], c);
        mx_col[d] = max(mx_col[d], c);
        mx_c[c][d] = max(mx_c[c][d], r);
        mn_c[c][d] = min(mn_c[c][d], r);
      }
    }
    // horizontal
    vi ans(10, 0);
    for (int r = 0; r < n; r++) {
      for (int d = 0; d < 10; d++) {
        if (mx_r[r][d] == -INF) continue;
        int base = mx_r[r][d] - mn_r[r][d];
        int h = max(r, n - r - 1);
        ans[d] = max(ans[d], base * h);
      }
    }
    // vertical
    for (int c = 0; c < n; c++) {
      for (int d = 0; d < 10; d++) {
        if (mx_c[c][d] == -INF) continue;
        int base = mx_c[c][d] - mn_c[c][d];
        int h = max(c, n - c - 1);
        ans[d] = max(ans[d], base * h);
      }
    }
    // third
    for (int r = 0; r < n; r++) {
      for (int d = 0; d < 10; d++) {
        // horizontal
        if (mx_r[r][d] != -INF) {
          int base = max(mx_r[r][d], n - 1 - mn_r[r][d]);
          int h = max(0, mx_row[d] - r);
          h = max(h, r - mn_row[d]);
          ans[d] = max(ans[d], base * h);
        }
      }
    }
    // third
    for (int c = 0; c < n; c++) {
      for (int d = 0; d < 10; d++) {
        // vertical
        if (mx_c[c][d] != -INF) {
          int base = max(mx_c[c][d], n - 1 - mn_c[c][d]);
          int h = max(0, mx_col[d] - c);
          h = max(h, c - mn_col[d]);
          ans[d] = max(ans[d], base * h);
        }
      }
    }
    for (int i = 0; i < 10; i++) cout << ans[i] << " \n"[i == 10 - 1];
  }
  return (0);
}
