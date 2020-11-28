// DP, Number Theory
// 5
// 27-11-2020

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
  const int mod = 1e9 + 7;
  auto add = [&] (int a, int b) { return (a + b) % mod; };
  auto sub = [&] (int a, int b) { return (a - b + mod) % mod; };
  auto mul = [&] (int a, int b) { return (1LL * a * b) % mod; };
  auto modPow = [&] (int a, int b) {
    int ret = 1;
    while (b) {
      if (b & 1) ret = mul(ret, a);
      a = mul(a, a);
      b >>= 1;
    }
    return ret;
  };
  int x, y;
  cin >> x >> y;
  if (y % x) {
    cout << 0 << '\n';
    return (0);
  }
  y /= x;
  map <int, int> dp;
  function <int(int)> rec = [&] (int x) -> int {
    if (dp.count(x)) return dp[x];
    int ret = modPow(2, x - 1);
    for (int d = 1; d * d <= x; d++) {
      if (x % d) continue;
      if (d != 1) ret = sub(ret, rec(x / d));
      if (d * d != x) ret = sub(ret, rec(d));
    }
    return dp[x] = ret;
  };
  cout << rec(y) << '\n';
  return (0);
}
