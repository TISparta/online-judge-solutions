// 2D BIT
// 3
// 21-09-2020

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
  vector <vi> ft(n + 1, vi(n + 1, 0));
  auto update2 = [&] (int r, int c, int val) {
    while (c < sz(ft)) {
      ft[r][c] += val;
      c += c & -c;
    }
  };
  auto update = [&] (int r, int c, int val) {
    while (r < sz(ft)) {
      update2(r, c, val);
      r += r & -r;
    }
  };
  auto sum2 = [&] (int r, int c) {
    int ret = 0;
    while (c) {
      ret += ft[r][c];
      c -= c & -c;
    }
    return ret;
  };
  auto sum = [&] (int r, int c) {
    int ret = 0;
    while (r) {
      ret += sum2(r, c);
      r -= r & -r;
    }
    return ret;
  };
  auto rect_sum = [&] (int r1, int c1, int r2, int c2) {
    return sum(r2, c2) - sum(r2, c1 - 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);
  };
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      if (s[j - 1] == '*') {
        update(i, j, 1);
      }
    }
  }
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      int val = rect_sum(r, c, r, c);
      if (val == 0) update(r, c, 1);
      if (val == 1) update(r, c, -1);
    } else {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      cout << rect_sum(r1, c1, r2, c2) << '\n';
    }
  }
  return (0);
}
