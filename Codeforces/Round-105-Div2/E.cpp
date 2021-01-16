// DP
// 4
// 15-01-2021

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
  int n, m;
  cin >> n >> m;
  const int INF = 1e9;
  vi dp(m + 1, -INF);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    vi a(k);
    for (int j = 0; j < k; j++) cin >> a[j];
    vi mx(k + 1, 0);
    int sum1 = 0;
    for (int t1 = 0; t1 < k; t1++) {
      sum1 += a[t1];
      int sum2 = 0;
      for (int t2 = k - 1; t2 > t1; t2--) {
        sum2 += a[t2];
        mx[k - t2] = max(mx[k - t2], sum2);
        mx[1 + t1 + k - t2] = max(mx[1 + t1 + k - t2], sum1 + sum2);
      }
      mx[1 + t1] = max(mx[1 + t1], sum1);
    }
    for (int j = m; j >= 1; j--) {
      for (int t = 1; t <= k and j - t >= 0; t++) {
        if (dp[j - t] == -INF) continue;
        dp[j] = max(dp[j], dp[j - t] + mx[t]);
      }
    }
  }
  cout << dp[m] << '\n';
  return (0);
}
