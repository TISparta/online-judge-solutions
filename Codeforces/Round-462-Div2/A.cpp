// Tags: Brute Force
// Difficulty: 1.5
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
  int n, m;
  cin >> n >> m;
  vll a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vll b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  ll ans = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    ll val = LLONG_MIN;
    for (int x = 0; x < n; x++) {
      if (x == i) continue;
      for (int y = 0; y < m; y++) {
        val = max(val, a[x] * b[y]);
      }
    }
    ans = min(ans, val);
  }
  cout << ans << '\n';
  return (0);
}
