/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : Math
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MOD = 1e9 + 7;

inline ll add (ll a, ll b) { return (a + b) % MOD; }
inline ll sub (ll a, ll b) { return (a + MOD - add(b, 0)) % MOD; }
inline ll mul (ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }

ll sum (ll n) {
  if (n % 2 == 0) return mul(n / 2, n + 1);
  return mul(n, (n + 1) / 2);
}

ll sum (ll from, ll to) {
  if (to < from) return 0LL;
  return sub(sum(to), sum(from - 1));
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    ll n, k;
    cin >> n >> k;
    ll ans = (k - 1) % MOD;
    ll range = k + n - 1;
    ll index = (k + n - 2 + n - 2) / (n - 1);
    ans = add(ans, mul(k, sum(2, index - 1)));
    ans = sub(ans, mul(range, sum(2, index - 1)));
    ans = add(ans, mul(range, max(0LL, index - 2)));
    ans = sub(ans, max(0LL, index - 2));
    cout << ans << '\n';
  }
  return (0);
}
