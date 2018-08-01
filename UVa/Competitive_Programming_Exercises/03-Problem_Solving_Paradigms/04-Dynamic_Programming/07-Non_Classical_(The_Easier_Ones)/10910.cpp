#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 70 + 5, MAX_T = 70;

int n, t, p;
long long memo[MAX_N][MAX_T];

long long dp (int id, int sum) {
  if (id == n) return sum == t;
  if (~memo[id][sum]) return memo[id][sum];
  long long ret = 0;
  for (int i = p; (n - id - 1) * p <= t - sum - i; i++) {
    ret += dp(id + 1, sum + i);
  }
  return memo[id][sum] = ret;
}

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> t >> p;
    memset(memo, -1, sizeof memo);
    cout << dp(0, 0) << endl;
  }
  return (0);
}
