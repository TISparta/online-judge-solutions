// Tags: Brute Force, Binary Search
// Difficulty: 7.0
// Priority: 3
// Date: 14-08-2021

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
  int n;
  cin >> n;
  map <int, int> cnt;
  for (int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    cnt[ai] += 1;
  }
  vll acc(n + 1, 0);
  vll acc2(n + 1, 0);
  vpii arr;
  for (auto [ai, frec]: cnt) acc[frec] += 1, acc2[frec] += frec, arr.eb(frec, ai);
  for (int i = n - 1; i >= 0; i--) acc[i] += acc[i + 1], acc2[i] += acc2[i + 1];
  ll mxr = 1, mxc = 1;
  for (ll r = 1; r <= n and acc[r] * r + (n - acc2[r]) >= r * r; r++) {
    ll lo = r, hi = n;
    while (lo != hi) {
      ll mid = (lo + hi + 1) >> 1;
      ll have = acc[r] * r + (n - acc2[r]);
      if (have >= r * mid) lo = mid;
      else hi = mid - 1;
    }
    ll c = lo;
    if (r * c > mxr * mxc) {
      mxr = r, mxc = c;
    }
  }
  sort(all(arr));
  cout << mxr * mxc << '\n';
  cout << mxr << ' ' << mxc << '\n';
  vector <vi> mat(mxr, vi(mxc, -1));
  for (int cc = 0; cc < mxc; cc++) {
    auto [frec, ai] = arr.back(); arr.pop_back();
    if (frec >= mxr) {
      int c = cc;
      for (int r = 0; r < mxr; r++) {
        mat[r][c] = ai;
        c = (c + 1) % mxc;
      }
    } else {
      int c = cc;
      for (int r = 0; r < mxr; r++) {
        if (frec == 0) {
          frec = arr.back().first;
          ai = arr.back().second;
          arr.pop_back();
        }
        mat[r][c] = ai;
        c = (c + 1) % mxc;
        frec -= 1;
      }
      if (frec != 0) arr.eb(frec, ai);
    }
  }
  for (int r = 0; r < mxr; r++) for (int c = 0; c < mxc; c++) cout << mat[r][c] << " \n"[c + 1 == mxc];
  return (0);
}
