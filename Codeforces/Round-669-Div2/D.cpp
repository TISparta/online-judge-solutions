// DP, Greedy
// 5
// 08-09-2020

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
  vi h(n);
  for (int& hi: h) cin >> hi;
  vector <vi> g(n);
  stack <int> s1;
  stack <int> s2;
  for (int i = 0; i < n; i++) {
    while (not s1.empty() and h[s1.top()] < h[i]) s1.pop();
    while (not s2.empty() and h[s2.top()] > h[i]) s2.pop();
    if (not s1.empty()) g[s1.top()].pb(i);
    if (not s2.empty()) g[s2.top()].pb(i);
    s1.push(i);
    s2.push(i);
  }
  s1 = stack <int> ();
  s2 = stack <int> ();
  for (int i = n - 1; i >= 0; i--) {
    while (not s1.empty() and h[s1.top()] < h[i]) s1.pop();
    while (not s2.empty() and h[s2.top()] > h[i]) s2.pop();
    if (not s1.empty()) g[i].pb(s1.top());
    if (not s2.empty()) g[i].pb(s2.top());
    s1.push(i);
    s2.push(i);
  }
  vi dp(n, -1);
  function <int(int)> rec = [&] (int pos) {
    if (pos == n - 1) return 0;
    if (dp[pos] != -1) return dp[pos];
    int ret = 1 + rec(pos + 1);
    for (int u: g[pos]) ret = min(ret, 1 + rec(u));
    return dp[pos] = ret;
  };
  cout << rec(0) << '\n';
  return (0);
}
