// Tags: Combinatorics
// Difficulty: 7.5
// Priority: 1
// Date: 19-08-2021

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

/*
(x1 - x) * (y2 - y) - (x2 - x) * (y1 - y)
x1 * (y2 - y) - x * (y2 - y) - x2 * (y1 - y) + x * (y1 - y)
x * (y1 - y - y2 + y) + x1 * (y2 - y) - x2 * (y1 - y)
x * (y1 - y2) + x1 * y2 - x1 * y - x2 * y1 + x2 * y
x * (y1 - y2) + y * (x2 - x1) + x1 * y2 - x2 * y1
*/

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll w, h;
  cin >> w >> h;
  vll cx(2);
  for (int x = 0; x <= w; x++) cx[x & 1] += 1;
  vll cy(2);
  for (int y = 0; y <= h; y++) cy[y & 1] += 1;
  int total = 0;
  const int mod = 1e9 + 7;
  for (int x1 = 0; x1 < 2; x1++) {
    for (int x2 = 0; x2 < 2; x2++) {
      for (int y1 = 0; y1 < 2; y1++) {
        for (int y2 = 0; y2 < 2; y2++) {
          ll addx = (cx[x1] * cx[x2]) % mod;
          ll addy = (cy[y1] * cy[y2]) % mod;
          ll add = (addx * addy) % mod;
          int dy = (y1 - y2 + 2) % 2;
          int dx = (x2 - x1 + 2) % 2;
          int dd = (x1 * y2 - x2 * y1 + 2) % 2;
          for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
              int rem = (x * dy + y * dx + dd) % 2;
              if (rem) continue;
              ll fadd = (add * cx[x] * cy[y]) % mod;
              total = (total + fadd) % mod;
            }
          }
        }
      }
    }
  }
  int degen = ((1 + w) * (1 + h)) % mod;
  for (int dx = 0; dx <= w; dx++) {
    for (int dy = 0; dy <= h; dy++) {
      if (dx == 0 and dy == 0) continue;
      ll g = gcd(dx, dy);
      ll p = ((w - dx + 1) * (h - dy + 1)) % mod;
      ll add = (3LL * g * p * (1 + (dx > 0)) * (1 + (dy > 0))) % mod;
      degen = (degen + add) % mod;
    }
  }
  total = (total - degen + mod) % mod;
  cout << total << '\n';
  return (0);
}
