// Tags: DP
// Difficulty: 5.7
// Priority: 1
// Date: 08-05-2021

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
  vi a(n);
  vector <vi> dp(n, vi(n));
  for (int i = 0; i < n; i++) cin >> dp[i][i];
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      dp[l][r] = dp[l][r - 1] ^ dp[l + 1][r];
    }
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      dp[l][r] = max({dp[l][r], dp[l][r - 1], dp[l + 1][r]});
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[l - 1][r - 1] << '\n';
  }
  return (0);
}
