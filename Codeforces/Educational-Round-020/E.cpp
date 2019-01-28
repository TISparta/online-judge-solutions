/**
 * > Author: TISparta
 * > Date: 07-01-18
 * > Tags: DP
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MX = 1e3 + 10;

int n, k, memo[MX][2 * MX], choice[MX][2 * MX];
string s;

int dp (int i, int dif) {
  if (i == n) return abs(dif) == k;
  if (abs(dif) == k) return false;
  int& ret = memo[i][dif + MX];
  int& c = choice[i][dif + MX];
  if (~ret) return ret;
  if (s[i] != '?') {
    ret = false;
    int val = 0;
    if (s[i] == 'W') val = 1;
    if (s[i] == 'L') val = -1;
    ret |= dp(i + 1, dif + val);
    c = dif + val;
  }
  else {
    ret = false;
    if (dp(i + 1, dif + 1)) {
      c = dif + 1;
      ret = true;
    }
    if (dp(i + 1, dif - 1)) {
      c = dif - 1;
      ret = true;
    }
    if (dp(i + 1, dif)) {
      c = dif;
      ret = true;
    }
  }
  return ret;
}

int main () {
  memset(memo, -1, sizeof memo);
  cin >> n >> k >> s;
  if (dp(0, 0)) {
    int pDif = 0;
    for (int i = 0; i < n; i++) {
      int nDif = choice[i][pDif + MX];
      if (nDif == pDif) cout << 'D';
      if (nDif == pDif + 1) cout << 'W';
      if (nDif == pDif - 1) cout << 'L';
      pDif = nDif;
    }
    cout << endl;
  }
  else cout << "NO" << endl;
  return (0);
}
