// DP
// 4
// 04-09-2020

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

const int N = 210;

int dp[N][N][N];

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  memset(dp, -1, sizeof dp);
  function <int(int,int,int)> rec = [&] (int pos, int a, int left) -> int {
    if (pos == sz(s)) return 0;
    if (dp[pos][a][left] != -1) return dp[pos][a][left];
    int ret = 0;
    int cost = (s[pos] == t[1]) ? a : 0;
    ret = max(ret, cost + rec(pos + 1, a + (s[pos] == t[0]), left)); // nothing
    if (left >= 1) ret = max(ret, rec(pos + 1, a + 1, left - 1)); // put a
    if (left >= 1) ret = max(ret, a + rec(pos + 1, a + (t[1] == t[0]), left - 1)); // put b
    return dp[pos][a][left] = ret;
  };
  cout << rec(0, 0, k) << '\n';
  return (0);
}
