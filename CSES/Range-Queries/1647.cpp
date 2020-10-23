// Sparse Table
// 2
// 20-09-2020

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
  int n, q;
  cin >> n >> q;
  const int W = 18;
  vector <vi> mn(n + 1, vi(W, INT_MAX));
  for (int i = 1; i <= n; i++) {
    cin >> mn[i][0];
  }
  for (int b = 1; b < W; b++) {
    for (int i = 1; i <= n; i++) {
      int j = i + (1 << (b - 1));
      if (j > n) break;
      mn[i][b] = min(mn[i][b - 1], mn[j][b - 1]);
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << mn[l][0] << '\n';
    } else {
      int x = 31 - __builtin_clz(r - l);
      cout << min(mn[l][x], mn[r - (1 << x) + 1][x]) << '\n';
    }
  }
  return (0);
}
