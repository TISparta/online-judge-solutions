// Tags: Greedy
// Difficulty: 1.7
// Priority: 5
// Date: 23-07-2021

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
    vector <vi> color(n + 1);
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      color[ai].pb(i);
    }
    vi z;
    int extra = 0;
    vi ans(n, 0);
    for (int i = 1; i <= n; i++) {
      if (empty(color[i])) continue;
      if (sz(color[i]) < k) {
        extra += sz(color[i]);
        for (int x: color[i]) z.pb(x);
      }
      if (sz(color[i]) >= k) {
        int cur = 1;
        for (int x: color[i]) {
          if (cur > k) break;
          ans[x] = cur;
          cur += 1;
        }
      }
    }
    while (sz(z) >= k) {
      for (int i = 0; i < k; i++) {
        int x = z.back(); z.pop_back();
        ans[x] = i + 1;
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
  }
  return (0);
}
