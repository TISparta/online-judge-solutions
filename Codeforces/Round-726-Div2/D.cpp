// Tags: Game Theory
// Difficulty: 5.0
// Priority: 5
// Date: 18-06-2021

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

vi bf (int from, int n) {
  vi dp(n + 1, 0);
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    vi div;
    for (int d = 2; d * d <= i; d++) {
      if (i % d) continue;
      div.pb(d);
      if (d != i / d) div.pb(i / d);
    }
    for (int d: div) if (dp[i - d] == 0) dp[i] = 1;
  }
  return dp;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  const int N = 100;
  vi dp = bf(1, N);
  int tt;
  cin >> tt;
  vector <string> ans;
  ans.pb("Bob");
  ans.pb("Alice");
  vll pp;
  for (int bit = 1; bit < 40; bit += 2) {
    pp.pb(1LL << bit);
  }
  while (tt--) {
    int n;
    cin >> n;
    int z = 0;
    if (n < N) {
      z = dp[n];
    } else {
      int p = 0;
      while (pp[p] <= n) p += 1;
      p -= 1;
      if (n == pp[p] or n == pp[p] + 1) {
        z = 0;
      } else {
        int d = n - pp[p];
        if (d & 1) z = 0;
        else z = 1;
      }
    }
    cout << ans[z] << '\n';
  }
  return (0);
}
