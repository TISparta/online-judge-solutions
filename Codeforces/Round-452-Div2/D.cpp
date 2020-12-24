// DP
// 4
// 24-12-2020

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

ll dp[12][2][2][2][2];

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll n;
  cin >> n;
  if (2 * n - 1 < 9) {
    cout << n * (n - 1) / 2 << '\n';
    return (0);
  }
  string s = "0" + to_string(n);
  int npos = 0;
  function <ll(int,int,int,int,int)> rec = [&] (int pos, int lt1, int lt2, int b1, int b2) -> ll {
    if (pos == sz(s)) return (b1 == 1 and b2 == 1) ? 1 : 0;
    if (dp[pos][lt1][lt2][b1][b2] != -1) return dp[pos][lt1][lt2][b1][b2];
    ll res = 0;
    int d = s[pos] - '0';
    int L1 = (lt1) ? 9 : d;
    int L2 = (lt2) ? 9 : d;
    for (int x = 0; x <= L1; x++) {
      for (int y = 0; y <= L2; y++) {
        if (npos <= pos and x + y != 9) continue;
        res += rec(pos + 1, max(lt1, int(x < d)), max(lt2, int(y < d)), max(b1, int(x != 0)), max(b2, int(y != 0)));
      }
    }
    return dp[pos][lt1][lt2][b1][b2] = res;
  };
  ll ans = 0;
  while (npos < sz(s)) {
    memset(dp, -1, sizeof dp);
    ll res = rec(0, 0, 0, 0, 0);
    if (res != 0) {
      ans = res / 2;
      break;
    }
    npos += 1;
  }
  cout << ans << '\n';
  return (0);
}
