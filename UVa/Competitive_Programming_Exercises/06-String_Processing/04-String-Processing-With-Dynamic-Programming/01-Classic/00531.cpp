#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 3e3 + 10;

int dp[MAX_LEN][MAX_LEN];
vector <string> s1, s2, ans;

void lcs () {
  int n = s1.size(), m = s2.size();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  int i = n, j = m;
  while (i and j) {
    if (s1[i - 1] == s2[j - 1]) {
      ans.push_back(s1[i - 1]);
      i--;
      j--;
    }
    else if (dp[i - 1][j] == dp[i][j]) i--;
    else j--;
  }
  reverse(begin(ans), end(ans));
  if (not ans.empty()) cout << ans[0];
  for (int i = 1; i < ans.size(); i++) cout << ' ' << ans[i];
  cout << endl;
  s1.clear(), s2.clear(), ans.clear();
}

bool read (vector <string>& s) {
  string line;
  bool endOfFile = true;
  while (getline(cin, line) and line[0] != '#') {
    endOfFile = false;
    istringstream token(line);
    string ss;
    while (token >> ss) s.push_back(ss);
  }
  return not endOfFile;
}

int main () {
  while (read(s1) and read(s2)) lcs();
  return (0);
}
