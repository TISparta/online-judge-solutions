// Tags: DP
// Difficulty: 4.5
// Priority: 1
// Date: 23-07-2021

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vi dp(n + 1, -1); // dp(i) = maximum number of fixed points with an array of size i
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = n; j > 0; j--) {
        if (dp[j - 1] == -1) continue;
        dp[j] = max(dp[j], dp[j - 1] + (a[i] == j));
      }
    }
    int ans = -1;
    for (int i = n; i >= 1; i--) {
      if (dp[i] >= k) {
        ans = n - i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
