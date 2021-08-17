// Tags: Brute Force
// Difficulty: 5.0
// Priority: 1
// Date: 17-08-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

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
  int ans = INT_MIN;
  for (int d = 1; d < n; d++) {
    if (n % d) continue;
    for (int i = 0; i < d and i + d + d < n; i++) {
      int sum = 0;
      for (int k = i; k < n; k += d) {
        sum += a[k];
      }
      ans = max(ans, sum);
    }
  }
  cout << ans << '\n';
  return (0);
}
