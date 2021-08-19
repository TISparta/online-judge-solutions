// Tags: Math
// Difficulty: 1.2
// Priority: 3
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
  int tt;
  cin >> tt;
  while (tt--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    int d = b - a;
    if (not (a <= d and d < b and b <= 2 * d and c <= 2 * d)) {
      cout << -1 << '\n';
    } else {
      int ans = (d < c) ? c - d : c + d;
      cout << ans << '\n';
    }
  }
  return (0);
}
