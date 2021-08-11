// Tags: Brute Force, DP
// Difficulty: 1.5
// Priority: 1
// Date: 30-07-2021

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
  const ll INF = 1e18;
  const int N = 2000;
  vll dp(N, INF);
  dp[6] = 15;
  dp[8] = 20;
  dp[10] = 25;
  for (int i = 11; i < 200; i++) {
    dp[i] = min({15 + dp[i - 6], 20 + dp[i - 8], 25 + dp[i - 10]});
  }
  dp[0] = 0;
  for (int i = N - 2; i >= 1; i--) {
    dp[i] = min(dp[i], dp[i + 1]);
  }
  int tt;
  cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    ll x = (n / 10);
    ll ans = ((n + 9) / (10)) * 25;
    for (int p = 0; p < 20; p++) {
      ll y = n - x * 10;
      if (y < 0) break;
      if (y >= N) continue;
      if (x < 0) break;
      ans = min(ans, x * 25 + dp[y]);
      x -= 1;
    }
    cout << ans << '\n';
  }
  return (0);
}
