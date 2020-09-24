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
  string s, t;
  cin >> s >> t;
  int n = sz(s);
  int m = sz(t);
  vector <vi> dp(n + 1, vi(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= m; i++) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = min(1 + dp[i][j - 1], 1 + dp[i - 1][j]);
      dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
    }
  }
  cout << dp[n][m] << '\n';
  return (0);
}
