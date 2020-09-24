// Number Theory, Binary Search
// 5
// 04-08-2020

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
  const int N = 1e7 + 10;
  vector <bool> is_prime(N, true);
  vi prime;
  for (ll i = 2; i < N; i++) {
    if (not is_prime[i]) continue;
    for (ll j = i * i; j < N; j += i) {
      is_prime[j] = false;
    }
    prime.pb(i);
  }
  vi acc(N, 0);
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int ai;
    cin >> ai;
    acc[ai]++;
  }
  for (int i = N - 2; i >= 1; i--) {
    acc[i] += acc[i + 1];
  }
  ll ans = 1;
  auto get_exp = [&] (ll n, ll p) {
    ll ret = 0;
    while (n) {
      ret = ret + n / p;
      n /= p;
    }
    return ret;
  };
  for (int p: prime) {
    ll e = 0;
    for (ll i = p; i < N; i *= p) {
      for (ll j = i; j < N; j += i) {
        e += acc[j];
      }
    }
    ll l = 1, r = 1e16;
    while (l != r) {
      ll m = (l + r) / 2;
      if (get_exp(m, p) < e) l = m + 1;
      else r = m;
    }
    ans = max(ans, l);
  }
  cout << ans << '\n';
  return (0);
}
