// Brute Force
// 1
// 13-10-2020

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
  int q;
  cin >> q;
  while (q--) {
    ll ans = LLONG_MAX;
    ll a, b, c;
    cin >> a >> b >> c;
    for (ll ai: {a - 1, a, a + 1}) {
      for (ll bi: {b - 1, b, b + 1}) {
        for (ll ci: {c - 1, c, c + 1}) {
          ans = min(ans, abs(ai - bi) + abs(ai - ci) + abs(bi - ci));
        }
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
