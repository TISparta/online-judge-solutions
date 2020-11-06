// DP
// 3
// 06-11-2020

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
  string s;
  cin >> s;
  int n = sz(s);
  vi a(n);
  for (int i = 0; i < n; i++) {
    a[i] = (s[i] - '0') % 3;
  }
  vector <vi> dp(n, vi(3, -1));
  function <int(int,int)> rec = [&] (int pos, int res) -> int {
    if (pos == n) return (res == 0);
    if (dp[pos][res] != -1) return dp[pos][res];
    int w = (res == 0 and pos);
    int ret = 0;
    int nres1 = (res + a[pos]) % 3;
    ret = max(ret, w + rec(pos + 1, nres1));
    int nres2 = a[pos];
    ret = max(ret, w + rec(pos + 1, nres2));
    return dp[pos][res] = ret;
  };
  cout << rec(0, 0) << '\n';
  return (0);
}
