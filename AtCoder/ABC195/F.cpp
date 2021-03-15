// DP
// 4
// 13-03-2021

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
  ll a, b;
  cin >> a >> b;
  int n = b - a + 1;
  const int N = 73;
  vi is_prime(N, 1);
  vi p;
  for (int u = 2; u < N; u++) {
    if (is_prime[u] == 0) continue;
    for (int v = 2 * u; v < N; v += u) is_prime[v] = 0;
    p.pb(u);
  }
  vi mask(n);
  for (ll x = a; x <= b; x++) {
    int b = 0;
    for (int bit = 0; bit < sz(p); bit++) {
      if (x % p[bit] == 0) b |= (1 << bit);
    }
    mask[x - a] = b;
  }
  const int ONES = 1 << 20;
  vector <vll> dp(n + 1, vll(ONES, 0));
  for (int j = 0; j < ONES; j++) dp[n][j] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < ONES; j++) {
      dp[i][j] = dp[i + 1][j];
      if (mask[i] & j) continue;
      dp[i][j] += dp[i + 1][j | mask[i]];
    }
  }
  cout << dp[0][0] << '\n';
  return (0);
}
