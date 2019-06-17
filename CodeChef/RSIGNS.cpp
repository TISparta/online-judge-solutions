/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : Math
 * > Difficulty : 3 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  const ll MOD = 1e9 + 7;
  auto mul = [&] (ll a, ll b) { return (a * b) % MOD; };
  auto modPow = [&] (ll a, ll b) {
    ll ret = 1;
    while (b) {
      if (b & 1) ret = mul(ret, a);
      a = mul(a, a);
      b >>= 1;
    }
    return ret;
  };
  int tc;
  cin >> tc;
  while (tc--) {
    ll k;
    cin >> k;
    cout << mul(10, modPow(2, k - 1)) << '\n';
  }
  return (0);
}
