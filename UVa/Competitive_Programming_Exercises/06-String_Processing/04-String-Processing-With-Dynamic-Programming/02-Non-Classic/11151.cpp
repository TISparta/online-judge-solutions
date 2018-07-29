#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e3 + 10;

string s;
int memo[MAX_LEN][MAX_LEN];

int dp (int i, int j) {
  if (i > j) return memo[i][j] = 0;
  if (~memo[i][j]) return memo[i][j];
  if (s[i] == s[j]) return memo[i][j] = (i == j ? 1 : 2) + dp(i + 1, j - 1);
  return memo[i][j] = max(dp(i, j - 1), dp(i + 1, j));
}

void clearCase () {
  for (int i = 0; i < s.size(); i++) for (int j = 0; j < s.size(); j++) memo[i][j] = -1;
}

int main () {
  int tc;
  cin >> tc;
  cin.ignore();
  while (tc--) {
    getline(cin, s);
    clearCase();
    cout << dp(0, s.size() - 1) << endl;
  }
  return (0);
}
