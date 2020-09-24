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
  int n, x;
  cin >> n >> x;
  vi c(n);
  for (int& ci: c) cin >> ci;
  vi dp(x + 1, 0);
  vector <bool> vis(x + 1, false);
  dp[0] = 1;
  vis[0] = true;
  const int mod = 1e9 + 7;
  for (int i = 0; i < x; i++) {
    if (not vis[i]) continue;
    for (int ci: c) {
      if (ci + i > x) continue;
      dp[ci + i] += dp[i];
      if (dp[ci + i] >= mod) dp[ci + i] -= mod;
      vis[ci + i] = true;
    }
  }
  cout << dp[x] << '\n';
  return (0);
}
