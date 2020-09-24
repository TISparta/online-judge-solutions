// DP
// 3
// 24-12-2018

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100 + 10, MAX_X = 1e4 + 10, oo = 1e9;

int n, X, memo[MAX_N][MAX_X];
vector <int> c;

int dp (int day, int cant) {
  if (cant < 0) return -oo;
  if (day == n) return 0;
  if (~memo[day][cant]) return memo[day][cant];
  return memo[day][cant] = max(1 + dp(day + 1, cant - (n - day) * c[day]), dp(day + 1, cant));
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> X;
  c.resize(n);
  for (int i = 0; i < n; i++) cin >> c[i];
  memset(memo, -1, sizeof memo);
  cout << dp(0, X) << endl;
  return (0);
}
