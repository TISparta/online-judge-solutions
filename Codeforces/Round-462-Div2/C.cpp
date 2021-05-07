// Tags: DP
// Difficulty: 4.5
// Priority: 1
// Date: 07-05-2021

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
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector <vi> dp(4, vi(n, -1));
  function <int(int,int)> rec = [&] (int id, int pos) -> int {
    if (id == 4 or pos == n) return 0;
    if (dp[id][pos] != -1) return dp[id][pos];
    int ret = max(rec(id, pos + 1), rec(id + 1, pos));
    if (1 + (id & 1) == a[pos]) ret = max(ret, 1 + rec(id, pos + 1));
    return dp[id][pos] = ret;
  };
  cout << rec(0, 0) << '\n';
  return (0);
}
