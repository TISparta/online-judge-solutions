/**
 * > Author: TISparta
 * > Date: 29-12-18
 * > Tags: Brute Force
 * > Difficulty: 1 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 60;

int n, grid[MAX_N][MAX_N];

bool check (int x, int y) {
  if (grid[x][y] == 1) return true;
  for (int s = 0; s < n; s++) for (int t = 0; t < n; t++) if (grid[x][y] == grid[x][s] + grid[t][y]) return true;
  return false;
}

int main () {
  cin >> n;
  for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) cin >> grid[r][c];
  bool ok = true;
  for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) ok &= check(r, c);
  puts(ok ? "Yes" : "No");
  return (0);
}
