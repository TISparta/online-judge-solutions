// Tags: DP
// Difficulty: 6.2
// Priority: 1
// Date: 22-07-2021

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
    int n;
    cin >> n;
    vi tag(n);
    for (int i = 0; i < n; i++) cin >> tag[i];
    vi s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    // dp(l, r) = dp(l, r + i) # Fix l
    // dp(l, r) = dp(l - i, r) # Fix r
    // Longer intervals depends on shorter intervals
    vll dp(n, 0);
    for (int r = 1; r < n; r++) {
      for (int l = r - 1; l >= 0; l--) {
        if (tag[l] == tag[r]) continue;
        ll dpr = dp[r];
        ll dpl = dp[l];
        ll score = abs(s[l] - s[r]);
        dp[l] = max(dp[l], score + dpr);
        dp[r] = max(dp[r], score + dpl);
      }
    }
    cout << *max_element(all(dp)) << '\n';
  }
  return (0);
}
