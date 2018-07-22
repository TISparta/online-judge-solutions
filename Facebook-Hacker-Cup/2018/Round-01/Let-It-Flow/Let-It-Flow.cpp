/**
 * > Author: TISparta
 * > Date: 21-07-18
 * > Tags: DP
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_R = 3, MAX_C = 1010, MAX_V = 4, MOD = 1e9 + 7;
const char EMPTY = '.';

ll dp[MAX_R][MAX_C][MAX_V];

int n;
vector <string> grid(MAX_R);

inline ll add (const ll a, const ll b) {
  return (a + b) % MOD;
}

void fillTable () {
  memset(dp, 0, sizeof dp);
  if (grid[0][0] == EMPTY) {
    dp[0][0][2] = 1;
    if (grid[1][0] == EMPTY) {
      dp[1][0][0] = 1;
    }
  }
  for (int c = 1; c < n; c++) {
    if (grid[0][c] == EMPTY) {
      dp[0][c][2] = dp[0][c - 1][1];
      if (grid[1][c] == EMPTY) {
        dp[0][c][1] = add(dp[0][c][1], add(dp[1][c - 1][0], dp[1][c - 1][1]));
      }
    }
    if (grid[1][c] == EMPTY) {
      dp[1][c][2] = add(dp[1][c][2], add(dp[1][c - 1][0], dp[1][c - 1][1]));
      dp[1][c][3] = add(dp[1][c][3], add(dp[1][c - 1][0], dp[1][c - 1][1]));
      if (grid[0][c] == EMPTY) {
        dp[1][c][0] = dp[0][c - 1][1];
      }
      if (grid[2][c] == EMPTY) {
        dp[1][c][1] = dp[2][c - 1][0];
      }
    }
    if (grid[2][c] == EMPTY) {
      dp[2][c][3] = dp[2][c - 1][0];
      if (grid[1][c] == EMPTY) {
        dp[2][c][0] = add(dp[2][c][0], add(dp[1][c - 1][0], dp[1][c - 1][1]));
      }
    }
  }
}

void readGrid () {
  cin >> n;
  for (int r = 0; r < MAX_R; r++) cin >> grid[r];
}

int main () {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    readGrid();
    fillTable();
    cout << "Case #" << t << ": " << dp[2][n - 1][0] << endl;
  }
  return (0);
}
