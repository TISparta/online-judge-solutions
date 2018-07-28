#include <bits/stdc++.h>

using namespace std;

const int W_DEL = 1, W_INS = 1, W_SUB = 1;

const int MAX_LEN = 1000 + 10;

string s1, s2;
int dp[MAX_LEN][MAX_LEN];

void stringAlignment () {
  int m = s1.size(), n = s2.size();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0) dp[0][j] = j * W_INS;
      else if (j == 0) dp[i][j] = i * W_DEL;
      else if (s1[j - 1] == s2[i - 1]) dp[i][j] = dp[i - 1][j - 1];
      else dp[i][j] = min(dp[i - 1][j - 1] + W_SUB, min(dp[i - 1][j] + W_DEL, dp[i][j - 1] + W_INS));
    }
  }
  cout << dp[n][m] << endl;
}

int main () {
  int x, y;
  while (cin >> x >> s1 >> y >> s2) stringAlignment();
  return (0);
}
