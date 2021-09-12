// Tags: Cumulative Array
// Difficulty: 3.3
// Priority: 4
// Date: 07-09-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  vector <string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  vector <vi> left(n, vi(m));
  vector <vi> right(n, vi(m));
  for (int r = 0; r < n; r++) {
    int ll = -1;
    for (int c = 0; c < m; c++) {
      if (s[r][c] == '#') ll = c;
      else left[r][c] = ll;
    }
    int rr = m;
    for (int c = m - 1; c >= 0; c--) {
      if (s[r][c] == '#') rr = c;
      else right[r][c] = rr;
    }
  }
  vector <vi> up(n, vi(m));
  vector <vi> down(n, vi(m));
  for (int c = 0; c < m; c++) {
    int ll = -1;
    for (int r = 0; r < n; r++) {
      if (s[r][c] == '#') ll = r;
      else up[r][c] = ll;
    }
    int rr = n;
    for (int r = n - 1; r >= 0; r--) {
      if (s[r][c] == '#') rr = r;
      else down[r][c] = rr;
    }
  }
  int ans = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (s[r][c] == '#') continue;
      ans = max(ans, (c - left[r][c]) + (right[r][c] - c) - 1 + (r - up[r][c]) + (down[r][c] - r) - 1 - 1);
    }
  }
  cout << ans << '\n';
  return (0);
}
