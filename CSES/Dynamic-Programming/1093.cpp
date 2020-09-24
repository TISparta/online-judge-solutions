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
  int n;
  cin >> n;
  const int mod = 1e9 + 7;
  if (n % 4 == 1 or n % 4 == 2) {
    cout << 0 << '\n';
    return (0);
  }
  int sum = n * (n + 1) / 4;
  vi dp(sum + 1, 0);
  vector <bool> vis(sum + 1, false);
  dp[0] = 1;
  vis[0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = sum - i; j >= 0; j--) {
      if (not vis[j]) continue;
      dp[i + j] += dp[j];
      vis[i + j] = true;
      if (dp[i + j] >= mod) dp[i + j] -= mod;
    }
  }
  auto mod_mod = [&] (ll a, ll b) {
    ll ret = 1;
    while (b) {
      if (b & 1) ret = (ret * a) % mod;
      a = (a * a) % mod;
      b >>= 1;
    }
    return ret;
  };
  int ans = (1LL * dp[sum] * mod_mod(2, mod - 2)) % mod; 
  cout << ans << '\n';
  return (0);
}
