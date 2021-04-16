// DP
// 4
// 16-04-2021

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
  cin >> n;
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector <vi> dp0(n + 1, vi(201, 0));
  vector <vi> dp1(n + 1, vi(201, 0));
  const int mod = 998244353;
  if (a[1] == -1) {
    for (int i = 1; i <= 200; i++) dp0[1][i] = 1;
  } else {
    dp0[1][a[1]] = 1;
  }
  for (int i = 2; i <= n + 1; i++) {
    for (int j = 1; j <= 200; j++) {
      dp0[i - 1][j] += dp0[i - 1][j - 1];
      if (dp0[i - 1][j] >= mod) dp0[i - 1][j] -= mod;
      dp1[i - 1][j] += dp1[i - 1][j - 1];
      if (dp1[i - 1][j] >= mod) dp1[i - 1][j] -= mod;
    }
    if (i == n + 1) break;
    int l, r;
    if (a[i] == -1) {
      l = 1, r = 200;
    } else {
      l = r = a[i];
    }
    for (int j = l; j <= r; j++) {
      {
        dp0[i][j] = dp0[i - 1][j - 1] + dp1[i - 1][j - 1];
        if (dp0[i][j] >= mod) dp0[i][j] -= mod;
      }
      {
        int add1 = dp0[i - 1][j] - dp0[i - 1][j - 1];
        if (add1 < 0) add1 += mod;
        int add2 = dp1[i - 1][200] - dp1[i - 1][j - 1];
        if (add2 < 0) add2 += mod;
        dp1[i][j] = add1 + add2;
        if (dp1[i][j] >= mod) dp1[i][j] -= mod;
      }
    }
  }
  cout << dp1[n][200] << '\n';
  return (0);
}
