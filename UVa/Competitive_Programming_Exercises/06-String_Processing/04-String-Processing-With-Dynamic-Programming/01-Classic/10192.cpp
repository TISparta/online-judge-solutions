#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e2 + 10;

string s1, s2;
int dp[MAX_LEN][MAX_LEN];

int lcs () {
  int n = s1.size(), m = s2.size();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[n][m];
}

int main () {
  int tc = 0;
  while (getline(cin, s1) and s1[0] != '#' and getline(cin, s2))
    printf("Case #%d: you can visit at most %d cities.\n", ++tc, lcs());
  return (0);
}
