// Brute Force
// 2
// 29-11-2020

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
    vi a(n);
    vi vis(101, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      vis[a[i]] = 1;
    }
    int ans = (n + k - 1) / k;
    for (int c = 1; c <= 100; c++) {
      if (vis[c] == 0) continue;
      int i = 0;
      int need = 0;
      while (i < n) {
        if (a[i] == c) {
          i += 1;
          continue;
        }
        i += k;
        need += 1;
      }
      ans = min(ans, need);
    }
    cout << ans << '\n';
  }
  return (0);
}
