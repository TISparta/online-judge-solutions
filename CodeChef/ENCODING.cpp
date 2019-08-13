/**
 * > Author : TISparta
 * > Date : 02-08-19
 * > Tags : DP
 * > Difficulty : 4 / 10
 */

#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

inline int add (int a, int b) { return (a + b) % MOD; }
inline int mul (int a, int b) { return (1LL * a * b) % MOD; }

int power[N];
pii dp[N][10][2];

void decrease (string& s) {
  for (int i = sz(s) - 1; i >= 0; i--) {
    s[i]--;
    if (s[i] >= '0') break;
    s[i] = '9';
  }
  if (s.front() == '0') s.erase(begin(s));
  if (s.empty()) s = "0";
}

pii rec (const string& s, int pos, int prev, int lt) {
  if (pos == sz(s)) return {0, 1};
  pii& ret = dp[pos][prev][lt];
  if (ret.second != -1) return ret;
  ret.first = 0;
  ret.second = 0;
  int g;
  if (lt) {
    for (int d = 0; d <= 9; d++) {
      g = 0;
      if (d != prev) g = mul(d, power[sz(s) - 1 - pos]);
      pii go = rec(s, pos + 1, d, lt);
      ret.first = add(ret.first, go.first);
      ret.first = add(ret.first, mul(g, go.second));
      ret.second = add(ret.second, go.second);
    }
  } else {
    for (int d = 0; d <= s[pos] - '0'; d++) {
      g = 0;
      if (d != prev) g = mul(d, power[sz(s) - 1 - pos]);
      pii go = rec(s, pos + 1, d, d < s[pos] - '0');
      ret.first = add(ret.first, go.first);
      ret.first = add(ret.first, mul(g, go.second));
      ret.second = add(ret.second, go.second);
    }
  }
  return ret;
}

int get (string& s, bool dec) {
  if (dec) decrease(s);
  for (int i = 0; i < sz(s); i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = pii(-1, -1);
  return rec(s, 0, 0, 0).first;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  power[0] = 1;
  for (int i = 1; i < N; i++) power[i] = mul(10, power[i - 1]);
  cin >> tc;
  while (tc--) {
    string nl, l, nr, r;
    cin >> nl >> l >> nr >> r;
    cout << (get(r, false) - get(l, true) + MOD) % MOD<< '\n';
  }
  return (0);
}
