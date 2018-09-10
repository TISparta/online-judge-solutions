/**
 * > Author : TISparta
 * > Date : 09-09-18
 * > Tags : Inclusion-Exclusion Principle
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int SZ = 1e6;

int t;
ll n, ans;
bool isPrime[SZ + 1];
vector <int> prime;

void sieve () {
  memset(isPrime, true, sizeof isPrime);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < SZ; i++)
    if (isPrime[i]) {
      for (ll j = 1LL * i * i; j < SZ; j += i) isPrime[j] = false;
      prime.push_back(i);
    }
}

void backtrack (int id, ll a, int sign) {
  int newSign = -1 * sign;
  for (int i = id; i < prime.size(); i++) {
    __int128_t aaa = __int128_t(a) * prime[i] * prime[i] * prime[i];
    if (aaa > n) break;
    ans += newSign * (n / aaa);
    backtrack(i + 1, aaa, newSign);
  }
}

void solve () {
  cin >> n;
  ans = 0;
  backtrack(0, 1, -1);
  cout << ans << endl;
}

int main () {
  sieve();
  cin >> t;
  while (t--) solve();
  return (0);
}
