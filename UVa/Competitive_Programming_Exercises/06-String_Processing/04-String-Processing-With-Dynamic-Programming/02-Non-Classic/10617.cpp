#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_LEN = 60 + 5;

ll memo[MAX_LEN][MAX_LEN];
string s;

ll dp (int i, int j) {
  if (i > j) return 1;
  if (~memo[i][j]) return memo[i][j];
  ll ret = dp(i, j - 1);
  for (int k = i; k <= j; k++) if (s[k] == s[j]) ret += dp(k + 1, j - 1);
  return memo[i][j] = ret;
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    memset(memo, -1, sizeof memo);
    cin >> s;
    cout << dp(0, s.size() - 1) - 1 << endl;
  }
  return (0);
}
