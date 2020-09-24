// DP
// 2
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
  int n;
  cin >> n;
  vi dp(n + 1, INT_MAX);
  dp[n] = 0;
  for (int i = n; i > 0; i--) {
    if (dp[i] == INT_MAX) continue;
    vi d;
    int x = i;
    while (x) d.pb(x % 10), x /= 10;
    for (int di: d) {
      dp[i - di] = min(dp[i - di], dp[i] + 1);
    }
  }
  cout << dp[0] << '\n';
  return (0);
}
