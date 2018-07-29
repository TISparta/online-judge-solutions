#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 80 + 5;

int dp(int, int);

string s;
int memo[MAX_LEN][MAX_LEN];

vector <int> Zfunction (const string s) {
  int n = (int) s.size();
  vector <int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int getFactorization (int i, int j) {
  if (i > j) return 0;
  int n = j - i + 1;
  string x = s.substr(i, j - i + 1);
  vector <int> z = Zfunction(x);
  int p = -1;
  for (int i = 1; i < n and p == -1; i++)
    if (n % i == 0 and z[i] + i == n) p = i;
  if (p == -1) return n;
  return dp(i, i + p - 1);
}

int dp (int i, int j) {
  if (~memo[i][j]) return memo[i][j];
  int ret = getFactorization(i, j);
  for (int k = i; k < j; k++)
    ret = min(ret, dp(i, k) + dp(k + 1, j));
  return memo[i][j] = ret;
}

int main () {
  while (cin >> s, s[0] != '*') {
    memset(memo, -1, sizeof memo);
    cout << dp(0, s.size() - 1) << endl;
  }
  return (0);
}
