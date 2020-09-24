// DP
// 2
// 12-09-2020

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, x;
  cin >> n >> x;
  vi c(n);
  for (int& ci: c) cin >> ci;
  vi dp(x + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < x; i++) {
    if (dp[i] == INT_MAX) continue;
    for (int ci: c) {
      if (ci + i > x) continue;
      dp[ci + i] = min(dp[ci + i], 1 + dp[i]);
    }
  }
  if (dp[x] == INT_MAX) cout << -1 << '\n';
  else cout << dp[x] << '\n';
  return (0);
}
