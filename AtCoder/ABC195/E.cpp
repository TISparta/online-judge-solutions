// Game Theory, DP
// 3
// 13-03-2021

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
  int n;
  string s, x;
  cin >> n >> s >> x;
  vi p7(n);
  p7[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    p7[i] = (10 * p7[i + 1]) % 7;
  }
  // View point: Takahashi
  vector <vi> dp(n, vi(7, -1));
  function <int(int,int)> rec = [&] (int pos, int res) -> int {
    if (pos == n) return (res == 0);
    if (dp[pos][res] != -1) return dp[pos][res];
    if (x[pos] == 'T') {
      int ret = max(rec(pos + 1, (res + p7[pos] * (s[pos] - '0')) % 7), rec(pos + 1, res));
      return dp[pos][res] = ret;
    } else {
      int ret = min(rec(pos + 1, (res + p7[pos] * (s[pos] - '0')) % 7), rec(pos + 1, res));
      return dp[pos][res] = ret;
    }
  };
  int win = rec(0, 0);
  if (win) cout << "Takahashi\n";
  else cout << "Aoki\n";
  return (0);
}
