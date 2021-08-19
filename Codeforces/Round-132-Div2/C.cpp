// Tags: Brute Force, Math
// Difficulty: 5.0
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

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll n, m, s;
  cin >> n >> m >> s;
  ll ans = 0;
  for (int b = 1; b <= m; b += 2) {
    for (int h = 1; h <= n; h += 2) {
      if (b * h < s or ((b * h) % 4 != s % 4)) continue;
      int res = (b * h - s) / 4;
      ll add = 0;
      if (res == 0) {
        add = 2 * (b / 2 + 1) * (h / 2 + 1) - 1;
      } else {
        for (int l1 = 1; l1 * 2 <= h; l1++) {
          if (res % l1 == 0 and 2 * (res / l1) <= b) add += 2;
        }
      }
      ll p = (n - h + 1) * (m - b + 1);
      ans += p * add;
    }
  }
  cout << ans << '\n';
  return (0);
}
