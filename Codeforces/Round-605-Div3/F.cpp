// DP
// 5
// 13-10-2020

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

const int N = 202;

int dp[N][N][2 * N];
tuple <char, int, int, int> nxt[N][N][2 * N];

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  string s1, s2;
  cin >> s1 >> s2;
  int n = sz(s1);
  int m = sz(s2);
  memset(dp, -1, sizeof dp);
  const int INF = 1e9;
  function <int(int,int,int)> rec = [&] (int p1, int p2, int open) -> int {
    if (open > n + m) return INF;
    if (p1 == n and p2 == m and open == 0) return 0;
    if (dp[p1][p2][open] != -1) return dp[p1][p2][open];
    int ret = INF;
    {
      int q1 = p1;
      if (q1 < n and s1[q1] == '(') q1++;
      int q2 = p2;
      if (q2 < m and s2[q2] == '(') q2++;
      if (not (p1 == n and p2 == m)) {
        int res = 1 + rec(q1, q2, open + 1);
        if (res < ret) {
          ret = res;
          nxt[p1][p2][open] = make_tuple('(', q1, q2, open + 1);
        }
      }
    }
    {
      int q1 = p1;
      if (q1 < n and s1[q1] == ')') q1++;
      int q2 = p2;
      if (q2 < m and s2[q2] == ')') q2++;
      if (open) {
        int res = 1 + rec(q1, q2, open - 1);
        if (res < ret) {
          ret = res;
          nxt[p1][p2][open] = make_tuple(')', q1, q2, open - 1);
        }
      }
    }
    return dp[p1][p2][open] = ret;
  };
  int len = rec(0, 0, 0);
  string ans = "";
  int p1 = 0, p2 = 0, open = 0;
  for (int i = 0; i < len; i++) {
    auto [ch, q1, q2, oo] = nxt[p1][p2][open];
    ans += ch;
    p1 = q1;
    p2 = q2;
    open = oo;
  }
  cout << ans << '\n';
  return (0);
}
