/**
 * > Author: TISparta
 * > Date: 27-01-19
 * > Tags: Mobius
 * > Difficulty: 5 / 10
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 1e5 + 10, MOD = 1e9 + 7;

typedef long long ll;

bool isPrime[MAX_A];
int mu[MAX_A];
int n, frec[MAX_A];

inline ll add (ll a, ll b) { 
  a = (a % MOD) + MOD;
  b = (b % MOD) + MOD;
  return (a + b) % MOD;
}
inline ll mul (ll a, ll b) { return (add(a, 0) * add(b, 0)) % MOD; }

void Mobius () {
  fill(isPrime, isPrime + MAX_A, true);
  fill(mu, mu + MAX_A, 1);
  isPrime[0] = isPrime[1] = false;
  for (ll u = 2; u < MAX_A; u++) {
    if (isPrime[u]) {
      for (ll v = u + u; v < MAX_A; v += u) {
        isPrime[v] = false;
        mu[v] *= -1;
      }
      mu[u] = -1;
      ll nu = u * u;
      for (ll nv = nu; nv < MAX_A; nv += nu) {
        mu[nv] = 0;
      }
    }
  }
}

ll modPow (ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b bitand 1) ret = mul(ret, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}

int main () {
  Mobius();
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    frec[a]++;
  }
  ll ans = 0;
  for (int u = 1; u < MAX_A; u++) {
    ll cnt = 0;
    for (int v = u; v < MAX_A; v += u) cnt += frec[v];
    ans = add(ans, mu[u] * add(modPow(2, cnt), -1));
  }
  cout << ans << endl;
  return (0);
}
