#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e3 + 10;

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
  while (getline(cin, s1), getline(cin, s2)) cout << lcs() << endl;
  return (0);
}
