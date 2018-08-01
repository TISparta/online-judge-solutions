#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 30 + 5, MAX_M = 20 + 5, INF = 1e7, MAX_T = 300 + 5;

int t1, t2, n, m[MAX_N], choice[MAX_N][MAX_T], c1[MAX_N][MAX_M], c2[MAX_N][MAX_M], memo[MAX_N][MAX_T][MAX_T];

void printSolution (int id, int a) {
  if (id == n) return;
  if (id) cout << ' ';
  cout << choice[id][a];
  printSolution(id + 1, a - choice[id][a]);
}

int dp (int id, int a, int b) {
  if (a < 0 or b < 0) return INF;
  if (id == n) return (a == 0 and b == 0) ? 0 : INF;
  if (~memo[id][a][b]) return memo[id][a][b];
  int ret = INF;
  for (int k = 0; k <= m[id]; k++) {
    int cost = c1[id][k] + c2[id][m[id] - k] + dp(id + 1, a - k, b - m[id] + k);
    if (cost < ret) {
      ret = cost;
      choice[id][a] = k;
    }
  }
  return memo[id][a][b] = ret;
}

bool read () {
  cin >> t1 >> t2;
  if (t1 + t2 == 0) return false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    for (int j = 1; j <= m[i]; j++) cin >> c1[i][j];
    for (int j = 1; j <= m[i]; j++) cin >> c2[i][j];
  }
  return true;
}

int main () {
  while (read()) {
    memset(memo, -1, sizeof memo);
    cout << dp(0, t1, t2) << endl;
    printSolution(0, t1);
    cout << endl << endl;
  }
  return (0);
}
