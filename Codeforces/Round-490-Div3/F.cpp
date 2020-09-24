// DP
// 4
// 08-01-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500 + 5, MAX_K = 10 + 5, MAX_VAL = 1e5 + 5;

int n, k, cnt[MAX_VAL], fav[MAX_VAL], h[MAX_K], memo[MAX_N][MAX_N * MAX_K];

int dp (int id, int left) {
  if (id == 0) return 0;
  if (~memo[id][left]) return memo[id][left];
  int ret = 0;
  for (int t = 0; t <= min(left, k); t++) {
    ret = max(ret, h[t] + dp(id - 1, left - t));
  }
  return memo[id][left] = ret;
}

int main () {
  cin >> n >> k;
  for (int i = 0; i < n * k; i++) {
    int c;
    cin >> c;
    cnt[c]++;
  }
  for (int i = 0; i < n; i++) {
    int f;
    cin >> f;
    fav[f]++;
  }
  for (int i = 1; i <= k; i++) cin >> h[i];
  int ans = 0;
  for (int f = 1; f < MAX_VAL; f++) {
    if (fav[f]) {
      for (int i = 0; i <= fav[f]; i++) for (int j = 0; j <= cnt[f]; j++) memo[i][j] = -1;
      ans += dp(fav[f], cnt[f]);
    }
  }
  cout << ans << endl;
  return  (0);
}
