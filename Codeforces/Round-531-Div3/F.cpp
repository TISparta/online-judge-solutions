/**
 * > Author: TISparta
 * > Date: 09-01-19
 * > Tags: DP, Bitmask
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 16 + 1, MAX_M = 1e4 + 10;

int n, m, w[MAX_N][MAX_N], wrap[MAX_N][MAX_N], mat[MAX_N][MAX_M], memo[1 << MAX_N][MAX_N][MAX_N];

int dp (int mask, int first, int last) {
  if (__builtin_popcount(mask) == n) return wrap[last][first];
  int& ret = memo[mask][first][last];
  if (~ret) return ret;
  ret = 0;
  for (int r = 0; r < n; r++) {
    if (((mask >> r) bitand 1) == 0) {
      ret = max(ret, min(w[last][r], dp(mask | (1 << r), first, r)));
    }
  }
  return ret;
}

int main () {
  cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mat[i][j];
  for (int r1 = 0; r1 < n; r1++) {
    for (int r2 = 0; r2 < n; r2++) {
      int k = INT_MAX;
      for (int c = 0; c < m; c++) k = min(k, abs(mat[r1][c] - mat[r2][c]));
      w[r1][r2] = k;
      k = INT_MAX;
      for (int c = 1; c < m; c++) k = min(k, abs(mat[r1][c - 1] - mat[r2][c]));
      wrap[r1][r2] = k;
    }
  }
  memset(memo, -1, sizeof memo);
  int k = 0;
  for (int r = 0; r < n; r++) k = max(k, dp(1 << r, r, r));
  cout << k << endl;
  return (0);
}
