// Tags: Brute Force
// Difficulty: 6.5
// Priority: 1
// Date: 04-04-2020

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
  const int D = 1e6 + 10;
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int& elem: a) cin >> elem;
  vector <vi> arr(D);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dif = abs(a[i] - a[j]);
      if (sz(arr[dif]) > 2 * k) continue;
      arr[dif].pb(a[i]);
      arr[dif].pb(a[j]);
    }
  }
  vector <bool> taken(D + 1, false);
  vector <bool> used(D + 1, false);
  for (int m = 1; m < D; m++) {
    vi rollback;
    int del = 0;
    for (int d = m; d < D; d += m) {
      if (arr[d].empty()) continue;
      if (sz(arr[d]) > 2 * k) {
        del = INT_MAX;
        break;
      }
      for (int ai: arr[d]) {
        if (used[ai]) continue;
        int aj = ai % m;
        if (taken[aj]) {
          del++;
        } else {
          taken[aj] = true;
        }
        used[ai] = true;
        rollback.pb(ai);
        if (del > k) break;
      }
    }
    if (del <= k) {
      cout << m << '\n';
      return (0);
    }
    for (int ai: rollback) {
      used[ai] = false;
      taken[ai % m] = false;
    }
  }
  return (0);
}
