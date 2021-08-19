// Tags: DP On Digits, IEP
// Difficulty: 6.5
// Priority: 1
// Date: 19-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

ll solve (ll x) {
  if (x == 0) return 1LL;
  vi bin;
  ll cx = x;
  while (cx != 0) {
    bin.pb(cx & 1);
    cx >>= 1;
  }
  reverse(all(bin));
  ll cnt = 1;
  for (int len = 1; len < sz(bin); len++) {
    vll dp(len, 0);
    for (int d1 = 1; d1 < len; d1++) {
      if (len % d1) continue;
      dp[d1] = 1LL << (d1 - 1);
      for (int d2 = d1 - 1; d2 >= 1; d2--) {
        if (d1 % d2 == 0) dp[d1] -= dp[d2];
      }
      cnt += dp[d1];
    }
  }
  int len = sz(bin);
  vll dp(len, 0);
  auto check = [&] (int d) {
    ll num = 0;
    for (int i = 0; i < d; i++) num = num * 2 + bin[i];
    ll t = num;
    for (int i = 1; i < len / d; i++) num = (num << d) + t;
    return (num <= x);
  };
  for (int d1 = 1; d1 < len; d1++) {
    if (len % d1) continue;
    vector <vll> memo(d1, vll(2, -1));
    function <ll(int,int)> rec = [&] (int pos, int lt) {
      if (pos == d1) return 1LL * lt;
      if (memo[pos][lt] != -1) return memo[pos][lt];
      ll ret = 0;
      if (lt) {
        ret = 1LL << (d1 - pos);
      } else {
        ret = ret + rec(pos + 1, lt | (0 < bin[pos]));
        if (1 == bin[pos]) ret = ret + rec(pos + 1, 0);
      }
      return memo[pos][lt] = ret;
    };
    dp[d1] = rec(1, 0) + check(d1);
    for (int d2 = d1 - 1; d2 >= 1; d2--) {
      if (d1 % d2 == 0) dp[d1] -= dp[d2];
    }
    assert(dp[d1] >= 0);
    cnt += dp[d1];
  }
  return cnt;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll l, r;
  cin >> l >> r;
  cout << solve(r) - solve(l - 1) << '\n';
  return (0);
}
