// Math
// 3
// 03-09-2020

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
  ll tc;
  cin >> tc;
  while (tc--) {
    ll x, y;
    cin >> x >> y;
    if (y <= x) {
      ll ans;
      if (x % 2 == 1) {
        ans = (x - 1) * (x - 1) + y;
      } else {
        ans = x * x - y + 1;
      }
      cout << ans << '\n';
    } else {
      ll ans;
      if (y % 2 == 0) {
        ans = (y - 1) * (y - 1) + x;
      } else {
        ans = y * y - x + 1;
      }
      cout << ans << '\n';
    }
  }
  return (0);
}
