// DP
// 4
// 08-02-2019

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 10, MOD = 1e9 + 7;

int dp[MAX_N];

int main () {
  int t, k;
  scanf("%d %d", &t, &k);
  dp[0] = 1;
  for (int i = 0; i < MAX_N; i++) {
    dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    if (i + k < MAX_N) dp[i + k] = (dp[i + k] + dp[i]) % MOD;
  }
  for (int i = 1; i < MAX_N; i++) {
    dp[i] = (dp[i - 1] + dp[i]) % MOD;
  }
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (dp[b] - dp[a - 1] + MOD) % MOD);
  }
  return (0);
}
