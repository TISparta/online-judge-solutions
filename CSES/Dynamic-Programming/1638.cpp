// DP
// 2
// 13-09-2020

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
  int n;
  cin >> n;
  vector <string> grid(n);
  for (int i = 0; i < n; i++) cin >> grid[i];
  vector <vi> dp(n + 1, vi(n + 1, 0));
  const int mod = 1e9 + 7;
  dp[1][1] = (grid[0][0] == '.');
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (grid[i - 1][j - 1] == '*') continue;
      dp[i][j] += dp[i][j - 1];
      if (dp[i][j] >= mod) dp[i][j] -= mod;
      dp[i][j] += dp[i - 1][j];
      if (dp[i][j] >= mod) dp[i][j] -= mod;
    }
  }
  cout << dp[n][n] << '\n';
  return (0);
}
