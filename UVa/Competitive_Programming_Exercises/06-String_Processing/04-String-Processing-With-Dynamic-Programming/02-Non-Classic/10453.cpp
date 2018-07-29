#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e3 + 10;

string s;
int memo[MAX_LEN][MAX_LEN], step[MAX_LEN * MAX_LEN];

int hash_ (int i, int j) {
  return (i + 1) * MAX_LEN + (j + 1);
}

string construct () {
  string ret = s;
  int i = 0, j = s.size() - 1, shift = 0;
  while (i <= j) {
    int next = step[hash_(i, j)];
    int ni = (next / MAX_LEN) - 1, nj = (next % MAX_LEN) - 1;
    if (make_pair(ni, nj) == make_pair(i + 1, j)) ret.insert(begin(ret) + j + 1 + shift, s[i]);
    if (make_pair(ni, nj) == make_pair(i, j - 1)) ret.insert(begin(ret) + i + shift, s[j]), shift++;
    i = ni, j = nj;
  }
  return ret;
}

int dp (int i, int j) {
  if (i > j) return 0;
  if (~memo[i][j]) return memo[i][j];
  if (s[i] == s[j]) {
    step[hash_(i, j)] = hash_(i + 1, j - 1);
    return memo[i][j] = dp(i + 1, j - 1);
  }
  int ret1 = dp(i, j - 1);
  int ret2 = dp(i + 1, j);
  step[hash_(i, j)] = (ret1 < ret2) ? hash_(i, j - 1) : hash_(i + 1, j);
  return memo[i][j] = 1 + min(ret1, ret2);
}

void clearCase () {
  for (int i = 0; i <= s.size(); i++) {
    for (int j = 0; j <= s.size(); j++) {
      memo[i][j] = step[i * MAX_LEN + j] = -1;
    }
  }
}

int main () {
  while (cin >> s) {
    clearCase();
    int add = dp(0, s.size() - 1);
    cout << add << ' ' << construct() << endl;
  }
  return (0);
}
