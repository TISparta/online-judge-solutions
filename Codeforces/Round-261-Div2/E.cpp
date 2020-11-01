// DP
// 5
// 22-09-2020

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
  const int mx_val = 1e5 + 1;
  vector <vpii> edges(mx_val);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[w].emplace_back(u, v);
  }
  vi dp(n + 1);
  vi f(n + 1);
  for (int i = 0; i < mx_val; i++) {
    for (auto pp: edges[i]) {
      f[pp.second] = 0;
    }
    for (auto pp: edges[i]) {
      f[pp.second] = max(f[pp.second], 1 + dp[pp.first]);
    }
    for (auto pp: edges[i]) {
      dp[pp.second] = max(dp[pp.second], f[pp.second]);
    }
  }
  cout << *max_element(all(dp)) << '\n';
  return (0);
}
