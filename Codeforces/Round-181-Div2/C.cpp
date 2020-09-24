// Combinatorics
// 3
// 03-08-2020

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
  const int N = 1e6 + 10;
  const int mod = 1e9 + 7;
  vi f(N);
  f[0] = f[1] = 1;
  for (ll i = 2; i < N; i++) f[i] = (i * f[i - 1]) % mod;
  auto mod_pow = [&] (ll a, ll b) {
    ll ret = 1;
    while (b) {
      if (b & 1) ret = (ret * a) % mod;
      b >>= 1;
      a = (a * a) % mod;
    }
    return ret;
  };
  vi inv_f(N);
  inv_f[N - 1] = mod_pow(f[N - 1], mod - 2);
  for (ll i = N - 2; i >= 0; i--) {
    inv_f[i] = (inv_f[i + 1] * (i + 1)) % mod;
  }
  auto comb = [&] (int a, int b) {
    ll x = (1LL * f[a] * inv_f[b]) % mod;
    return (x * inv_f[a - b]) % mod;
  };
  int a, b, n;
  cin >> a >> b >> n;
  int ans = 0;
  for (int x = 0; x <= n; x++) {
    int sum = x * a + (n - x) * b;
    bool ok = true;
    while (sum) {
      int d = sum % 10;
      ok &= (d == a or d == b);
      sum /= 10;
    }
    if (not ok) continue;
    ans = (ans + comb(n, x)) % mod;
  }
  cout << ans << '\n';
  return (0);
}
