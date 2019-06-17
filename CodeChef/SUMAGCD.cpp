/**
 * > Author : TISparta
 * > Date : 17-06-19
 * > Tags : Number Theory
 * > Difficulty : 4 / 10
 */

#pragma comment (linker,"/STACK:1024000000") 
#pragma GCC optimize(2)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int gcd (int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector <int> arr(n);
    int mx = 1;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] > mx) mx = arr[i];
    }
    sort(all(arr));
    arr.erase(unique(all(arr)), end(arr));
    int ans = 0;
    for (ll dd = 1; dd * dd <= arr[0]; dd++) {
      if (arr[0] % dd) continue;
      for (int d: {dd, arr[0] / dd}) {
        int g1 = -1, g2 = -1;
        for (int i = 0; i < sz(arr); i++) {
          if (arr[i] % d == 0) {
            if (g1 == -1) g1 = arr[i];
            else g1 = gcd(g1, arr[i]);
          } else {
            if (g2 == -1) g2 = arr[i];
            else g2 = gcd(g2, arr[i]);
          }
        }
        if (g1 == -1 or g2 == -1) ans = max(ans, max(g1, g2) + mx);
        else if (g1 + g2 > ans) ans = g1 + g2;
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
