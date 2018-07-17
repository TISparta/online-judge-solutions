/**
 * > Author: TISparta
 * > Date: 16-08-18
 * > Tags: DP
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e4, MAX_VAL = 100, MOD = 101;

int n, a[MAX_N + 10], memo[MAX_N + 10][MAX_VAL + 10];
string used, op;

void print () {
  cout << a[0];
  for (int i = 1; i < n; i++) {
    putchar(i - 1 < op.size() ? op[i - 1] : '*');
    cout << a[i];
  }
  putchar('\n');
}

bool dp (int result, int id = 1) {
  if (result == 0) {
    op = used;
    return true;
  }
  if (id == n) return false;
  if (~memo[id][result]) return memo[id][result];
  bool ret = false;
  for (char ch: "+-*") {
    if (ret) break;
    used.push_back(ch);
    if (ch == '+') ret |= dp((result + a[id]) % MOD, id + 1);
    if (ch == '-') ret |= dp((result - a[id] + MOD) % MOD, id + 1);
    if (ch == '*') ret |= dp((result * a[id]) % MOD, id + 1);
    used.pop_back();

  }
  return memo[id][result] = ret;
}

int main () {
  memset(memo, -1, sizeof memo);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  dp(a[0]);
  print();
  return (0);
}
