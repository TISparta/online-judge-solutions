/**
 * > Author: TISparta
 * > Date: 16-08-18
 * > Tags: Game Theory, DP
 * > Difficulty: 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 310;

int GN[MAX_N];

int Grundy (int n) {
  if (~GN[n]) return GN[n];
  set <int> N;
  for (int i = 0; i < n; i++) N.insert(Grundy(i) xor Grundy(n - i - 1));
  for (int i = 0; i + 1 < n; i++) N.insert(Grundy(i) xor Grundy(n - i - 2));
  int ret = 0;
  while (N.count(ret)) ret++;
  return GN[n] = ret;
}

void precal () {
  memset(GN, -1, sizeof GN);
  GN[0] = 0, GN[1] = 1, GN[2] = 2;
  for (int i = 3; i < MAX_N; i++) GN[i] = Grundy(i);
}

void solve () {
  int sum_xor = 0;
  string line, s;
  getline(cin, line);
  getline(cin, line);
  istringstream token(line);
  while (getline(token, s, 'X')) sum_xor ^= GN[s.size()];
  puts(sum_xor ? "WIN" : "LOSE");
}

int main () {
  precal();
  int tc;
  cin >> tc;
  cin.ignore();
  while (tc--) solve();
  return (0);
}
