// Combinatorics
// 4
// 09-12-2020

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

namespace NT {
  int mod = 1e9 + 7;
  vi fact;
  vi inv_fact;

  inline int norm (ll a) {
    a %= mod;
    if (a < 0) a += mod;
    return a;
  }

  inline bool is_ok (ll x) {
    return (0 <= x and x < mod);
  }

  inline int add (ll a, ll b) {
    if (not is_ok(a)) a = norm(a);
    if (not is_ok(b)) b = norm(b);
    ll ret = a + b;
    if (ret >= mod) ret -= mod;
    return ret;
  }

  inline int sub (ll a, ll b) {
    if (not is_ok(a)) a = norm(a);
    if (not is_ok(b)) b = norm(b);
    ll ret = a - b;
    if (ret < 0) ret += mod;
    return ret;
  }

  inline int mul (ll a, ll b) {
    if (not is_ok(a)) a = norm(a);
    if (not is_ok(b)) b = norm(b);
    return (a * b) % mod;
  }

  int bin_pow (ll a, ll b) {
    int ret = 1;
    while (b) {
      if (b & 1) ret = mul(ret, a);
      a = mul(a, a);
      b >>= 1;
    }
    return ret;
  }

  int inv (ll a) {
    return bin_pow(a, mod - 2);
  }

  void preprocess_factorial (int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
    inv_fact[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = mul(inv_fact[i + 1], i + 1);
  }

  int comb (int a, int b) {
    if (a < b) return 0;
    return mul(mul(fact[a], inv_fact[b]), inv_fact[a - b]);
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  NT::preprocess_factorial(n * m);
  // x
  int ans = 0;
  int ways = NT::comb(n * m - 2, k - 2);
  for (int d = 1; d < n; d++) {
    int f = NT::mul(d, NT::mul(n - d, NT::mul(m, m)));
    int add = NT::mul(ways, f);
    ans = NT::add(ans, add);
  }
  // y
  for (int d = 1; d < m; d++) {
    int f = NT::mul(d, NT::mul(m - d, NT::mul(n, n)));
    int add = NT::mul(ways, f);
    ans = NT::add(ans, add);
  }
  cout << ans << '\n';
  return (0);
}
