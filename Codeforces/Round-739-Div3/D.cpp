// Tags: Brute Force
// Difficulty: 3.3
// Priority: 4
// Date: 18-08-2021

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
  vector <string> z;
  for (int bit = 0; bit <= 60; bit++) {
    z.pb(to_string(1LL << bit));
  }
  int tt;
  cin >> tt;
  while (tt--) {
    string a;
    cin >> a;
    int n = sz(a);
    int ans = 1000000;
    for (string b: z) {
      int m = sz(b);
      int match = 0;
      for (int i = 0; i < n and match < m; i++) if (a[i] == b[match]) match += 1;
      int need = n - match + m - match;
      ans = min(ans, need);
    }
    cout << ans << '\n';
  }
  return (0);
}
