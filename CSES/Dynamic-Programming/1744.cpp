// DP
// 4
// 13-09-2020

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
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  vector <vi> dp(a + 1, vi(b + 1, -1));
  function <int(int,int)> rec = [&] (int a, int b) -> int {
    if (a > b) swap(a, b);
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    int ret = INT_MAX;
    for (int x = 1; x < a; x++) {
      ret = min(ret, 1 + rec(x, b) + rec(a - x, b));
    }
    for (int y = 1; y < b; y++) {
      ret = min(ret, 1 + rec(a, y) + rec(a, b - y));
    }
    return dp[a][b] = ret;
  };
  cout << rec(a, b) << '\n';
  return (0);
}
