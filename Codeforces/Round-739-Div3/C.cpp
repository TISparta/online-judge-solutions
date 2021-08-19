// Tags: Binary Search
// Difficulty: 1.7
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
    ll k;
    cin >> k;
    ll lo = 1, hi = 1e5;
    while (lo != hi) {
      ll mid = (lo + hi) >> 1;
      if (k <= mid * mid) hi = mid;
      else lo = mid + 1;
    }
    if (lo * lo - lo + 1 <= k) {
      cout << lo << ' ' << 1 + (lo * lo - k) << '\n';
    } else {
      ll s = (lo - 1) * (lo - 1) + 1;
      cout << 1 + (k - s) << ' ' << lo << '\n';
    }
  }
  return (0);
}
