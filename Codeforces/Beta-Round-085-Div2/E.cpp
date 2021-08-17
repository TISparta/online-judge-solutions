// Tags: DP, Bitmask
// Difficulty: 6.5
// Priority: 2
// Date: 31-07-2020

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

const int ONES = 1 << 6 + 1;

int n, m;
short dp[ONES][ONES][ONES][42];

int take (int mask, vi bits) {
  for (int p: bits) {
    if (not (0 <= p and p < n)) continue;
    mask = mask & (~(1 << p));
  }
  return mask;
}

int rec (int mask1, int mask2, int mask3, int pos) {
  int r = pos / m;
  int c = pos % m;
  if (pos == n * m + m - 1) return 0;
  if (r == n) {
    return rec(mask2, mask3, (1 << n) - 1, c + 1);
  }
  if (dp[mask1][mask2][mask3][pos] != -1) return dp[mask1][mask2][mask3][pos];
  int ret = INT_MAX;
  if ((mask1 >> r) & 1) {
    ret = min(ret, 1 + rec(take(mask1, {r - 1, r, r + 1}), take(mask2, {r}), mask3, pos + m));
    ret = min(ret, 1 + rec(take(mask1, {r, r + 1, r + 2}), take(mask2, {r + 1}), mask3, pos + m));
    ret = min(ret, 1 + rec(take(mask1, {r}), take(mask2, {r - 1, r, r + 1}), take(mask3, {r}), pos + m));
  } else {
    ret = rec(mask1, mask2, mask3, pos + m);
  }
  return dp[mask1][mask2][mask3][pos] = ret;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) cout << n * m - (m + 2) / 3 << '\n';
  else if (n == 2) cout << n * m - (m / 2) - 1 << '\n';
  else cout << n * m - rec((1 << n) - 1, (1 << n) - 1, (1 << n) - 1, 0) << '\n';
  return (0);
}
