// Brute Force
// 4
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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 2) {
    cout << -1 << '\n';
    return (0);
  }
  int ans = INT_MAX;
  for (int i = 0; i + 1 < n; i++) {
    int val1 = 0;
    for (int j = i; j >= max(0, i - 32); j--) {
      val1 ^= a[j];
      int val2 = 0;
      for (int k = i + 1; k < min(n, i + 1 + 32); k++) {
        val2 ^= a[k];
        if (val1 > val2) {
          ans = min(ans, i - j + k - i - 1);
        }
      }
    }
  }
  if (ans == INT_MAX) ans = -1;
  cout << ans << '\n';
  return (0);
}
