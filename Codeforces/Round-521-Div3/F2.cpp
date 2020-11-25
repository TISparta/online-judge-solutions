// DP, Min Queue
// 5
// 24-11-2020

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

template <typename T>
struct MinQueue {
  // arr_1 <= arr_2 <= ... <= arr_t
  deque <T> arr;
  MinQueue () {}

  void add (T val) {
    while (not arr.empty() and val < arr.back()) arr.pop_back();
    arr.pb(val);
  }

  void remove (T val) {
    if (arr.front() == val) arr.pop_front();
  }

  T get_min () const { return arr.front(); }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  const ll INF = 1e15;
  vector <vll> dp(n + 1, vll(x + 1, -INF));
  vll a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[n][0] = 0;
  vector <MinQueue <ll>> qq(x);
  for (int j = x - 1; j >= 0; j--) qq[j].add(-dp[n][j]);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 1; j <= x; j++) {
      int l = i + 1;
      int r = min(n, i + k);
      dp[i][j] = a[i] - qq[j - 1].get_min();
      if (i + k <= n) {
        qq[j - 1].remove(-dp[i + k][j - 1]);
      }
      qq[j - 1].add(-dp[i][j - 1]);
      /*
      for (int ii = i + 1; ii <= min(n, i + k); ii++) {
        dp[i][j] = max(dp[i][j], a[i] + dp[ii][j - 1]);
      }
      */
    }
  }
  ll ans = -INF;
  for (int i = 0; i < k; i++) ans = max(ans, dp[i][x]);
  if (ans < 0) ans = -1;
  cout << ans << '\n';
  return (0);
}
