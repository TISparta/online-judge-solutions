#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e3 + 10;

vector <string> s1, s2;

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

bool read (vector <string>& s) {
  s.clear();
  bool endOfFile = true;
  string line, token = "";
  if (getline(cin, line)) endOfFile = false;
  for (const char ch: line) {
    if (isalnum(ch)) token += ch;
    else {
      if (not token.empty()) s.push_back(token);
      token = "";
    }
  }
  if (not token.empty()) s.push_back(token);
  return not endOfFile;
}

int main () {
  int tc = 0;
  while (read(s1) and read(s2)) {
    if (s1.empty() or s2.empty()) printf("%2d. Blank!\n", ++tc);
    else printf("%2d. Length of longest match: %d\n", ++tc, lcs());
  }
  return (0);
}
