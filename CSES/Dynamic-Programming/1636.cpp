// DP
// 3
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
  sort(all(c));
  vi dp(x + 1, 0);
  dp[0] = 1;
  const int mod = 1e9 + 7;
  for (int ci: c) {
    for (int i = 0; i < x; i++) {
      if (ci + i > x) break;
      dp[ci + i] += dp[i];
      if (dp[ci + i] >= mod) dp[ci + i] -= mod;
    }
  }
  cout << dp[x] << '\n';
  return (0);
}
