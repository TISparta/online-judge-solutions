// Tags: Brute Force
// Difficulty: 1.0
// Priority: 4
// Date: 16-01-2021

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
  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector <vi> match(n + 1, vi(n + 1, 0));
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    match[x][y] = match[y][x] = 1;
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (i == j or i == k or j == k) continue;
        if (match[i][j] and match[i][k] and match[j][k]) {
          ans = min(ans, a[i] + a[j] + a[k]);
        }
      }
    }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
  return (0);
}
