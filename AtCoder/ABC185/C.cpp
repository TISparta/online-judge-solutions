// DP
// 2
// 13-12-2020

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
  ll n;
  cin >> n;
  vector <vll> dp(n + 1, vll(12, 0));
  for (int i = 0; i < n; i++) dp[i][0] = 1;
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 1; j <= 11; j++) {
      for (int k = i + 1; k < n; k++) {
        dp[i][j] += dp[k][j - 1];
      }
    }
  }
  cout << dp[0][11] << '\n';
  return (0);
}
